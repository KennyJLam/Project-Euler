//
// Created by KLam on 10/5/2015.
//

#include "solve_p080.h"
#include <iostream>
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP080()
{
    const uint num_decimals = 100;
    const uint max = 100;

    ull total_sum = 0;

    for (uint n = 1; n < max; ++n)
    {
        BigInt<int> c = n;
        BigInt<int> p = 0;
        for (uint d = 0; d < num_decimals; ++d)
        {
            bool is_perfect_square = false;
            for (int i = 9; i >= 0; --i)
            {
                BigInt<int> test = p;
                test *= 10;
                test *= (2 * i);
                test += (i * i);
                if (test < c)
                {
                    c -= test;
                    c *= 100;
                    p *= 10;
                    p += i;
                    total_sum += i;
                    break;
                }
                else if (test == c)
                {
                    is_perfect_square = true;
                    break;
                }
            }
            if (is_perfect_square)
                break;
        }
    }

    ull solution = total_sum;
    cout << "P080 solution: " << solution << endl;
}