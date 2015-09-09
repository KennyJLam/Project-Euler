//
// Created by KLam on 9/9/2015.
//

#include "solve_p031.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP031()
{
    const int ar_length = 8;
    int counts[ar_length] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    ull num_matches = 0;
    const int target = 200;

    for (;;)
    {
        int value = counts[0] +
                    counts[1] * 2 +
                    counts[2] * 5 +
                    counts[3] * 10 +
                    counts[4] * 20 +
                    counts[5] * 50 +
                    counts[6] * 100 +
                    counts[7] * 200;
        if (value >= target)
        {
            if (value == target)
                ++num_matches;
            for (int i = 0; i < ar_length; ++i)
            {
                if (counts[i] == 0)
                    continue;
                if (i >= ar_length - 1)
                    goto EXIT_LOOP; // nested break
                counts[i] = 0;
                ++counts[i + 1];
                break;
            }
        }
        else
            counts[0] += target - value;
    }
    EXIT_LOOP:

    ull solution = num_matches;
    cout << "P031 solution: " << solution << endl;
}