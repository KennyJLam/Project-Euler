//
// Created by KLam on 9/24/2015.
//

#include "solve_p065.h"
#include <iostream>
#include "math_utils.h"
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP065()
{
    const uint max = 100;

    vector<uint> sequence(1, 2);
    uint mod = 0;
    uint k = 1;
    for (uint i = 2; i <= max; ++i)
    {
        if (mod == 1)
        {
            sequence.push_back(2 * k);
            ++k;
        }
        else
            sequence.push_back(1);
        ++mod;
        mod %= 3;
    }

    BigInt<uint> big_int1(1);
    BigInt<uint> big_int2(0);

    BigInt<uint>* num = &big_int1;
    BigInt<uint>* denom = &big_int2;

    for (auto i = sequence.rbegin(); i != sequence.rend(); ++i)
    {
        uint term = *i;
        BigInt<uint>* temp = num;
        num = denom;
        denom = temp;

        BigInt<uint> big_temp(*denom);
        big_temp *= term;
        num->Add(big_temp);
    }

    ull sum = 0;
    for (uint digit : num->digits())
    {
        sum += digit;
    }

    ull solution = sum;
    cout << "P065 solution: " << solution << endl;
}