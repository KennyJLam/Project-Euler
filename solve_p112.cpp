//
// Created by KLam on 10/27/2015.
//

#include "solve_p112.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP112()
{
    ull target_percent = 99;
    ull non_bouncy_percent = 100 - target_percent;

    ull num_bouncy = 0;
    ull num_non_bouncy = 0;
    ull n;
    for (n = 1;;++n)
    {
        ull test = n;
        bool up = false, down = false, is_bouncy = false;
        ull last = n % 10;
        test /= 10;
        while (test > 0)
        {
            ull current = test % 10;
            if (current > last)
                down = true;
            else if (current < last)
                up = true;
            last = current;
            if (up && down)
            {
                is_bouncy = true;
                break;
            }
            test /= 10;
        }
        if (is_bouncy)
            ++num_bouncy;
        else
            ++num_non_bouncy;
        if (num_bouncy * non_bouncy_percent == num_non_bouncy * target_percent)
            break;
    }
    ull target = n;

    ull solution = target;
    cout << "P112 solution: " << solution << endl;
}
