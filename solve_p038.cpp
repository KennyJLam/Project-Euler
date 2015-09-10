//
// Created by KLam on 9/10/2015.
//

#include "solve_p038.h"
#include <iostream>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP038()
{
    const ull max = 1000000000;
    ull max_match = 0;
    for (uint n = 2; n <= 6; ++n)
    {
        ull target = 2;
        for (;;)
        {
            ull build = 0;
            for (int i = 1; i <= n; ++i)
            {
                ull scratch = target * i;
                build = build * pow_int<ull>(10, num_digits_int(scratch)) + scratch;
            }
            if (build > max)
                break;
            if (IsPanDigital(build, 9) && build > max_match)
                max_match = build;
            ++target;
        }
    }

    ull solution = max_match;
    cout << "P038 solution: " << solution << endl;
}