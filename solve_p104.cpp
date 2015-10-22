//
// Created by KLam on 10/22/2015.
//

#include "solve_p104.h"
#include <iostream>
#include <algorithm>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP104()
{
    ull prev = 1;
    ull prev2 = 1;
    ull match;
    const long double phi = (1 + sqrt(5)) / 2;
    for (ull n = 3;;++n)
    {
        ull current = prev + prev2;
        current %= 1000000000;
        prev2 = prev;
        prev = current;

        if (current < 1e8 || !IsPanDigital(current, 9))
            continue;

        long double fib_log = n * log10(phi) - log10(5) / 2;
        long double residue = fib_log - (ull)fib_log;
        ull digits = (ull)(pow(10, residue) * 1e8);
        if (IsPanDigital(digits, 9))
        {
            match = n;
            break;
        }
    }


    ull solution = match;
    cout << "P104 solution: " << solution << endl;
}
