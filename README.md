# Factorial-Permutations
Calculates the K-th permutations of N! permutations of a sequence of permutations from 0 to N-1.

See: https://math.stackexchange.com/questions/2665171/formula-to-get-a-unique-combination-for-n-values-from-0-to-n-1

See: https://codereview.stackexchange.com/questions/188413/calculate-permutation-from-factorial-representation-of-the-k-th-iteration-of-the

```C++
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

///<summary>Calculates the permutation of K in range of 0 to N!. (MAX of N = 20--2^61).</summary>
vector<size_t> factorial_permutation(size_t N, uint64_t K) {
    vector<size_t> Perm;

    uint64_t FactN = N,  //Factorial of N
        RmdrK = K, //Remainder of K/(N-1)!
        IterN = N, //Downward iterator for N
        PostK; //The factorial position of K for each sub permutation.

    for (uint64_t I = N - 1; I > 1; I--)
        FactN *= I;
    for (uint64_t I = 1; I <= N; I++) {
        FactN /= IterN--;
        PostK = RmdrK / FactN;
        RmdrK = RmdrK - (PostK * FactN);
        Perm.push_back(PostK);
    }

    return Perm;
}

int main() {
    size_t N = 5;
    uint64_t K = 4;
    vector<size_t> c = factorial_permutation(N, K);
    vector<size_t> s; //The factorial permutation sequence
    vector<size_t> e; //The permutation built from the factorial sequence

    //Builds the basic order sequence 0 to N-1 before permutation.
    for (int i = 0; i < N; i++)
        s.push_back(i);

    //Pushes the final result converted from factorial permutation to real permutation. For each entry of sequence s[c[i]] is an index into e[i] to build the permutation.
    for (int i = 0; i < N; i++) {
        e.push_back(s[c[i]]);
        s.erase(s.begin() + c[i]);
    }

    // Outputs the final permutation.
    for (int i = 0; i < N; i++)
        cout << e[i];

    cin.get();
};
```
