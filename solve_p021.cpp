//
// Created by KLam on 8/31/2015.
//

#include "solve_p021.h"
#include <iostream>
#include "math_utils.h"
#include <map>

typedef unsigned long long ull;
using namespace std;

void euler::SolveP021()
{
    const int max = 10000;
    set<int> amicable_set;
    map<int,int> divisor_sums;

    for (int target = 1; target < max; ++target)
    {
        set<int> divisors;
        GetDivisors(target, divisors);
        ull sum = 0;
        for (int divisor : divisors)
        {
            if (divisor != target)
                sum += divisor;
        }
        if (divisor_sums.find(target) != divisor_sums.end() && sum == divisor_sums[target])
        {
            amicable_set.insert(divisor_sums[target]);
            amicable_set.insert(target);
        }
        divisor_sums[sum] = target;
    }

    ull sum = 0;
    for (int amicable : amicable_set)
    {
        sum += amicable;
    }
    ull solution = sum;
    cout << "P021 solution: " << solution << endl;
}