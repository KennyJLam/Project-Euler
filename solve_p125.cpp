//
// Created by KLam on 10/30/2015.
//

#include "solve_p125.h"
#include <iostream>
#include <algorithm>
#include "generators/palindrone_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static bool num_cubes(ull value);
}

bool euler::num_cubes(ull value)
{
    if (is_perfect_square(value))
        return false;

    ull ubound = (ull)sqrt(value);
    ull lbound = ubound;
    ull sum = ubound * ubound;

    for(;;)
    {
        while (sum < value)
        {
            --lbound;
            if (lbound == 0)
                return false;
            sum += lbound * lbound;
        }
        while (sum > value)
        {
            sum -= ubound * ubound;
            --ubound;
        }
        if (sum == value)
            return true;
    }
}

void euler::SolveP125()
{
    const ull ceiling = 100000000;
    PalindromeGenerator<ull> gen;
    ull total_sum = 0;

    for (;;)
    {
        ull palindrome = gen.GetNext();
        if (palindrome >= ceiling)
            break;
        if (num_cubes(palindrome))
            total_sum += palindrome;

    }

    ull solution = total_sum;
    cout << "P125 solution: " << solution << endl;
}