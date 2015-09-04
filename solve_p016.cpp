//
// Created by KLam on 8/31/2015.
//

#include "solve_p016.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;

void euler::SolveP016()
{
    const int exp = 1000;
    vector<int> digits;
    digits.push_back(1);

    for (int i = 0; i < exp; ++i)
    {
        int carry = 0;
        for (std::size_t j = 0; j < digits.size(); ++j)
        {
            int prev = digits[j];
            digits[j] = ((digits[j] * 2 + carry) % 10);
            carry = prev >= 5 ? 1 : 0;
        }
        if (carry == 1)
            digits.push_back(1);
    }

    ull sum = 0;
    for (size_t i = 0; i < digits.size(); ++i)
    {
        sum += digits[i];
    }
    ull solution = sum;
    cout << "P016 solution: " << solution << endl;
}
