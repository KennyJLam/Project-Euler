//
// Created by KLam on 10/28/2015.
//

#include "solve_p119.h"
#include <iostream>
#include <algorithm>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

// Completely arbitrary bounds used based on inspection.  Not proof that this works.
void euler::SolveP119()
{
    const ull target = 30;

    set<tuple<ull,ull,ull>> matches;
    for (ull base = 2; base <= 100; ++base)
    {
        for (ull exp = 1; exp <= 15; ++exp)
        {
            ull candidate = pow_int(base, exp);
            if (candidate < 10)
                continue;
            ull sum = 0;
            ull temp = candidate;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == base)
                matches.insert(make_tuple(candidate, base, exp));
        }
    }

    ull solution;
    int i = 0;
    for (auto t : matches)
    {
        ++i;
        if (i == target)
            solution = get<0>(t);
    }
    cout << "P119 solution: " << solution << endl;
}