//
// Created by KLam on 9/1/2015.
//

#include "solve_p028.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP028()
{
    const uint max = 1001;

    ull sum = 1;

    for (uint i = 3; i <= max; i += 2)
    {
        sum += 4 * i * i - 6 * i + 6;
    }

    ull solution = sum;
    cout << "P028 solution: " << solution << endl;
}
