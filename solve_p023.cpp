//
// Created by KLam on 9/1/2015.
//

#include "solve_p023.h"
#include "math_utils.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

bool euler::IsAbundant(uint target)
{
    uint sum = 1;
    double root = sqrt(target);
    for (uint i = 2; i < root; ++i)
    {
        if (target % i == 0)
        {
            sum += i;
            sum += target / i;
            if (sum > target)
                return true;
        }
    }
    if ((uint)root * (uint)root == target && target != 1) // check for perfect square
        return sum + root > target;
    return false;
}

void euler::SolveP023()
{
    const int max = 28123;
    const int min = 12;
    vector<uint> abundants;
    set<uint> abundant_set;

    for (uint target = 1; target <= 40000; ++target)
    {
        if (IsAbundant(target))
        {
            abundants.push_back(target);
            abundant_set.insert(target);
        }

    }

    ull sum = 0;
    for (uint target = 1; target <= max; ++target)
    {
        bool abundant_sum = false;
        for (int i = 0; i < abundants.size(); ++i)
        {
            uint abundant = abundants[i];
            if (abundant > target / 2)
                break;
            if (abundant_set.find(target - abundant) != abundant_set.end())
            {
                abundant_sum = true;
                break;
            }
        }
        if (!abundant_sum)
            sum += target;
    }

    ull solution = sum;
    cout << "P023 solution: " << solution << endl;
}
