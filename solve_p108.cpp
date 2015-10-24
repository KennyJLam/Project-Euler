//
// Created by KLam on 10/23/2015.
//

#include "solve_p108.h"
#include <iostream>
#include <algorithm>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP108()
{
    const ull max = 1000;
    ull n;
    PrimeGenerator<ull> gen;
    for (n = 2;;++n)
    {
        map<ull,ull> prime_factors = gen.PrimeFactorFreq(n);
        ull num_factors = 1;
        for (const auto& p : prime_factors)
        {
            num_factors *= (2 * p.second) + 1;
        }
        ull num_solutions = (num_factors + 1) / 2;

        if (num_solutions > max)
            break;
    }

    ull solution = n;
    cout << "P108 solution: " << solution << endl;
}
