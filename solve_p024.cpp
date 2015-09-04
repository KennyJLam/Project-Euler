//
// Created by KLam on 9/1/2015.
//

#include "solve_p024.h"
#include "math_utils.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP024()
{
    const int max = 1000000;
    vector<uint> indices(10, 0);

    for (int i = 1; i < max; ++i)
    {
        ++indices[9];
        for (int j = 1; j <= 10; ++j)
        {
            if (indices[10 - j] >= j)
            {
                indices[10 - j] %= j;
                ++indices[10 - j - 1];
            }
        }
    }

    string pool = "0123456789";
    string digits = "";

    for (int i = 0; i < 10; ++i)
    {
        char digit = pool[indices[i]];
        digits += digit;
        pool.erase(pool.begin() + indices[i]);
    }

    string solution = digits;
    cout << "P024 solution: " << solution << endl;
}

