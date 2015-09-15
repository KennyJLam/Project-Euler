//
// Created by KLam on 9/14/2015.
//

#include "solve_p048.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP048()
{
    const uint max_digits = 10;
    const uint limit = 1000;
    uint adder[max_digits];
    uint multiplier[max_digits];

    for (uint digit = 0; digit < max_digits; ++digit)
    {
        adder[digit] = 0;
    }

    for (uint n = 1; n <= limit; ++n)
    {
        multiplier[0] = 1;
        for (uint digit = 1; digit < max_digits; ++digit)
        {
            multiplier[digit] = 0;
        }

        for (int m = 0; m < n; ++m)
        {
            for (uint digit = 0; digit < max_digits; ++digit)
            {
                multiplier[digit] *= n;
            }

            for (uint digit = 0; digit < max_digits; ++digit)
            {
                if (multiplier[digit] >= 10)
                {
                    if (digit < max_digits - 1)
                        multiplier[digit + 1] += multiplier[digit] / 10;
                    multiplier[digit] %= 10;
                }
            }
        }

        for (uint digit = 0; digit < max_digits; ++digit)
        {
            adder[digit] += multiplier[digit];
            if (adder[digit] >= 10)
            {
                adder[digit] %= 10;
                if (digit < max_digits - 1)
                    ++adder[digit + 1];
            }
        }
    }

    ull sum = 0;
    ull exp = 1;
    for (uint digit = 0; digit < max_digits; ++digit)
    {
        sum += exp * adder[digit];
        exp *= 10;
    }
    ull solution = sum;
    cout << "P048 solution: " << solution << endl;
}
