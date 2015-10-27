//
// Created by KLam on 10/27/2015.
//

#include "solve_p113.h"
#include <iostream>
#include <algorithm>
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    ull binom(ull n, ull r);
}

ull euler::binom(ull n, ull r)
{
    ull binomial = n;
    ull num_coeff = n - 1;
    ull denom_coeff = 2;

    for (ull k = 2; k <= (n - r); ++k)
    {
        binomial *= num_coeff;
        binomial /= denom_coeff;

        --num_coeff;
        ++denom_coeff;
    }

    return binomial;
}

void euler::SolveP113()
{
    const ull exp = 100;

    ull count = 0;
    for (ull i = 2; i < exp; ++i)
    {
        ull n = 10 + i - 1;
        ull b = binom(n, i);
        count += b - 10;
    }

    ull binomial = binom(10 + exp - 1, exp);
    count += 2 * binomial - 11;

    ull solution = count;
    cout << "P113 solution: " << solution << endl;
}