//
// Created by KLam on 9/16/2015.
//

#include "solve_p053.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP053()
{
    const ull floor = 1000000;
    const uint max = 100;

    uint count = 0;

    for (uint n = 1; n <= max; ++n)
    {
        ull binomial = n;
        uint num_coeff = n - 1;
        uint denom_coeff = 2;

        for (uint r = 2; r < n; ++r)
        {
            binomial *= num_coeff;
            binomial /= denom_coeff;

            if (binomial > floor)
            {
                count += (n + 1 - 2 * r);
                break;
            }


            --num_coeff;
            ++denom_coeff;
        }
    }

    ull solution = count;
    cout << "P053 solution: " << solution << endl;
}