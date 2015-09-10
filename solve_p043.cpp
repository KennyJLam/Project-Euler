//
// Created by KLam on 9/10/2015.
//

#include "solve_p043.h"
#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP043()
{
    vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ull sum = 0;

    do
    {
        int test = digits[1] * 100 + digits[2] * 10 + digits[3];
        if (test % 2 != 0)
            continue;
        test = digits[2] * 100 + digits[3] * 10 + digits[4];
        if (test % 3 != 0)
            continue;
        test = digits[3] * 100 + digits[4] * 10 + digits[5];
        if (test % 5 != 0)
            continue;
        test = digits[4] * 100 + digits[5] * 10 + digits[6];
        if (test % 7 != 0)
            continue;
        test = digits[5] * 100 + digits[6] * 10 + digits[7];
        if (test % 11 != 0)
            continue;
        test = digits[6] * 100 + digits[7] * 10 + digits[8];
        if (test % 13 != 0)
            continue;
        test = digits[7] * 100 + digits[8] * 10 + digits[9];
        if (test % 17 != 0)
            continue;

        ull value = 0;
        for (int digit : digits)
        {
            value = value * 10 + digit;
        }
        sum += value;
    }
    while (next_permutation(digits.begin(), digits.end()));

    ull solution = sum;
    cout << "P043 solution: " << solution << endl;
}