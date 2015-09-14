//
// Created by KLam on 9/10/2015.
//

#include "solve_p041.h"
#include "math_utils.h"
#include "generators/prime_generator.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP041()
{
    PrimeGenerator<ull> gen;
    ull max_prime = 0;

    int n = 0;
    int next_pow10 = 1;
    // Apparently it has to be 7 digits because if the summation of digits
    // of a number is divisible by 3, the number is divisible by 3.
    while (n <= 7)
    {
        ull prime = gen.NextPrime();
        if (prime > next_pow10)
        {
            ++n;
            next_pow10 *= 10;
        }
        if (IsPanDigital(prime, n) && prime > max_prime)
            max_prime = prime;
    }

    ull solution = max_prime;
    cout << "P041 solution: " << solution << endl;
}