//
// Created by KLam on 9/22/2015.
//

#include "solve_p063.h"
#include <iostream>
#include "math_utils.h"
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP063()
{
    ull count = 0;
    for (ull n = 1; n <= 9; ++n)
    {
        BigInt<ull> value(n);
        uint num_digits = value.digits().size();
        uint exponent = 1;
        do
        {
            if (num_digits == exponent)
                ++count;
            ++exponent;
            value *= n;
            num_digits = value.digits().size();
        }
        while (exponent <= num_digits);
    }

    ull solution = count;
    cout << "P063 solution: " << solution << endl;
}