//
// Created by KLam on 8/27/2015.
//

#include "solve_p006.h"
#include <iostream>

using namespace std;

void euler::SolveP006()
{
    long long target = 100;

    long long sum = target * (target + 1) / 2;
    long long sum2 = target * (target + 1) * (2 * target + 1) / 6;

    long long solution = sum * sum - sum2;
    cout << "P006 solution: " << solution << endl;
}