#include <vector>

///<summary>Calculates the factorial permutation of K in range of 0 to N!. (MAX of N = 20--2^61).</summary>
vector<size_t> factorial_permutation(size_t N, uint64_t K) {
    vector<size_t> Perm;

    uint64_t FactN = N,  //Factorial of N
        RmdrK = K, //Remainder of K/(N-1)!
        IterN = N, //Downward iterator for N
        PostK; //The factorial position of K for each sub permutation.
    
    //Quick factor factorial as a compact loop.
    if (N > 1) {
        for(uint64_t I = N; I-- > 2; FactN *= I);
    } else { FactN = 1; }

    for (uint64_t I = 1; I <= N; I++) {
        FactN /= IterN--;
        PostK = RmdrK / FactN;
        RmdrK = RmdrK - (PostK * FactN);
        Perm.push_back(PostK);
    }

    return Perm;
}
