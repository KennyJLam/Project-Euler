//
// Created by KLam on 10/7/2015.
//

#include "solve_p085.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP085()
{
    const ull target = 2000000;
    uint best_width = 0, best_height = 0;
    ll best_error = target;

    for (uint height = 1;;++height)
    {
        bool exit = false;
        for (uint width = 1;;++width)
        {
            ull num_squares = 0;

            for (uint h = 1; h <= height; ++h)
            {
                for (uint w = 1; w <= width; ++w)
                {
                    num_squares += (width - w + 1) * (height - h + 1);
                }
            }

            ll error = target - num_squares;
            if (error < 0)
                error *= -1;
            if (error < best_error)
            {
                best_error = error;
                best_width = width;
                best_height = height;
            }

            if (num_squares > target)
            {
                if (width == height)
                    exit = true;
                break;
            }
        }
        if (exit)
            break;
    }

    ull solution =  best_width * best_height;
    cout << "P085 solution: " << solution << endl;
}
