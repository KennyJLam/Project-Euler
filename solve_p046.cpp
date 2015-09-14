//
// Created by KLam on 9/14/2015.
//

#include "solve_p046.h"
#include <iostream>
#include "generators/prime_generator.h"
#include <cmath>


typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP046()
{
    PrimeGenerator<ull> gen;

    ull match = 0;
    for(ull n = 9;;n += 2)
    {
        if (gen.IsPrime(n))
            continue;
        bool found_decomp = false;
        for (ull prime : gen.primes())
        {
            if (prime >= n)
                break;
            ull remainder = n - prime;
            if (remainder % 2 != 0)
                continue;
            remainder /= 2;
            ull root = (ull)floor(sqrt(remainder));
            if (root * root == remainder)
            {
                found_decomp = true;
                break;
            }
        }
        if (!found_decomp)
        {
            match = n;
            break;
        }
    }

    ull solution = match;
    cout << "P046 solution: " << solution << endl;
}