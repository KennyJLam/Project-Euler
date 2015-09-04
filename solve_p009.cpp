//
// Created by KLam on 8/27/2015.
//

#include "solve_p009.h"
#include <iostream>

using namespace std;

void euler::SolveP009()
{
    const int abc_sum = 1000;
    int a = 0, b = 0 ,c = 0;

    for (c = abc_sum / 3; c < abc_sum / 2; ++c)
    {
        int ab_sum = abc_sum - c;
        if (ab_sum / 2 > c || ab_sum < c)
            continue;
        for (a = 1; a <= ab_sum; ++a)
        {
            b = ab_sum - a;
            if (!(a < b && b < c))
                continue;
            if ((a * a + b * b) == (c * c))
                goto EXIT_LOOP;
        }
    }
    EXIT_LOOP:
    int solution = a * b * c;
    cout << "P009 solution: " << solution << endl;
}