//
// Created by KLam on 9/15/2015.
//

#include "solve_p050.h"
#include <iostream>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP050()
{
    const ull max = 1000000;
    PrimeGenerator<ull> gen(max);
    uint max_chain = 0;
    ull match = 0;

    for (ull prime : gen.primes())
    {
        ull sum = prime;
        if (prime * max_chain > max)
            break;
        uint current_chain = 0;
        gen.SetFloor(prime);
        while (sum < max)
        {
            ++current_chain;
            if (gen.IsPrime(sum))
            {
                if (current_chain > max_chain)
                {
                    match = sum;
                    max_chain = current_chain;
                }
            }
            sum += gen.NextPrime();
        }
    }

    ull solution = match;
    cout << "P050 solution: " << solution << endl;
}