//
// Created by Klam on 10/28/2015.
//

#include "solve_p120.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP120()
{
    const ull target = 1000;
    ull sum = 0;

    for (ull a = 3; a <= target; ++a)
    {
        if ((a % 4) % 2 == 0)
            sum += a * (a - 2);
        else
            sum += a * (a - 1);
    }

    ull solution = sum;
    cout << "P120 solution: " << solution << endl;
}