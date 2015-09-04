//
// Created by KLam on 8/31/2015.
//

#include "solve_p020.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;

void euler::SolveP020()
{
    const int max = 100;
    vector<ull> digits;
    digits.push_back(1);

    for (int i = 2; i <= max; ++i)
    {
        ull carry = 0;
        for (std::size_t j = 0; j < digits.size(); ++j)
        {
            ull product = digits[j] * i + carry;
            digits[j] = product % 10;
            carry = product / 10;
        }
        if (carry != 0)
        {
            while (carry > 0)
            {
                digits.push_back(carry % 10);
                carry /= 10;
            }

        }

    }

    ull sum = 0;
    for (size_t i = 0; i < digits.size(); ++i)
    {
        sum += digits[i];
    }
    ull solution = sum;
    cout << "P020 solution: " << solution << endl;
}