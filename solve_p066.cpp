//
// Created by KLam on 9/24/2015.
//

#include "solve_p066.h"
#include <iostream>
#include "math_utils.h"
#include "continued_fractions_util.h"
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP066()
{
    const uint max = 1000;
    uint best_D = 0;
    BigInt<ull> best_x = 0;

    for (uint D = 2; D <= max; ++D)
    {
        if (is_perfect_square(D))
            continue;
        ull term0;
        vector<ull> terms;
        get_sqrt_terms<ull>(D, term0, terms);
        BigInt<ull> prev_num = 1, prev2_num = 0;
        BigInt<ull> prev_denom = 0, prev2_denom = 0;
        BigInt<ull> num = term0, denom = 1;
        auto iter = terms.begin();
        for (;;)
        {
            BigInt<ull> x_temp(num), y_temp(denom);
            x_temp *= num;
            y_temp *= denom;
            y_temp *= D;
            y_temp += 1;

            if (x_temp == y_temp)
            {
                if (num > best_x)
                {
                    best_x = num;
                    best_D = D;
                }
                break;
            }

            ull term = *iter;
            prev2_num = prev_num;
            prev2_denom = prev_denom;
            prev_num = num;
            prev_denom = denom;

            num = prev_num;
            num *= term;
            num += prev2_num;
            denom = prev_denom;
            denom *= term;
            denom += prev2_denom;

            ++iter;
            if (iter == terms.end())
                iter = terms.begin();
        }
    }

    ull solution = best_D;
    cout << "P066 solution: " << solution << endl;
}