//
// Created by KLam on 9/15/2015.
//

#include "solve_p049.h"
#include <iostream>
#include "generators/prime_generator.h"
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP049()
{
    const uint max = 9999;
    PrimeGenerator<uint> gen(max);
    gen.SetFloor(1000);
    uint match1 = 0, match2 = 0, match3 = 0;

    for (uint prime = gen.NextPrime(); prime < max; prime = gen.NextPrime())
    {
        bool exit_loop = false;
        for (uint step = 2; step < (max - prime) / 2; step += 2)
        {
            if (prime == 1487 && step == 3330)
                continue;
            uint prime2 = prime + step;
            uint prime3 = prime + 2 * step;
            if (gen.IsPrime(prime2) && gen.IsPrime(prime3) && AreDigitsEquals(prime, prime2) && AreDigitsEquals(prime2, prime3))
            {

                match1 = prime;
                match2 = prime2;
                match3 = prime3;
                exit_loop = true;
                break;
            }
        }
        if (exit_loop)
            break;
    }

    ull exp = 1;
    ull sum = 0;

    while (match3 > 0)
    {
        sum += exp * (match3 % 10);
        match3 /= 10;
        exp *= 10;
    }
    while (match2 > 0)
    {
        sum += exp * (match2 % 10);
        match2 /= 10;
        exp *= 10;
    }
    while (match1 > 0)
    {
        sum += exp * (match1 % 10);
        match1 /= 10;
        exp *= 10;
    }

    ull solution = sum;
    cout << "P049 solution: " << solution << endl;
}