//
// Created by KLam on 9/28/2015.
//

#include "solve_p073.h"
#include <iostream>
#include <map>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP073()
{
    const uint max_denom = 12000;
    const uint upper_num = 1;
    const uint upper_denom = 2;
    const uint lower_num = 1;
    const uint lower_denom = 3;

    PrimeGenerator<uint> gen(max_denom);
    ull count = 0;

    for (uint d = 2; d <= max_denom; ++d)
    {
        ull n_ceil = d * upper_num / upper_denom;
        if (d % upper_denom == 0 || upper_denom % d == 0)
            --n_ceil;
        ull n_floor = d * lower_num / lower_denom + 1;
        if (n_ceil == 0 || n_ceil < n_floor)
            continue;
        set<uint> prime_factors;
        gen.PrimeFactors(d, prime_factors);
        for (ull n = n_floor; n <= n_ceil; ++n)
        {
            bool is_coprime = true;
            for (uint prime_factor : prime_factors)
            {
                if (n % prime_factor == 0)
                {
                    is_coprime = false;
                    break;
                }
            }
            if (is_coprime)
                ++count;
        }
    }

    ull solution = count;
    cout << "P073 solution: " << solution << endl;
}
