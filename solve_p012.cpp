//
// Created by KLam on 8/28/2015.
//

#include "solve_p012.h"
#include <iostream>
#include "prime_utils.h"
#include "math_utils.h"

using namespace std;

int euler::GetNumDivisors(long long target, int min_num_factors)
{
    vector<long long> factors;
    set<long long> divisors;
    GetPrimeFactors(target, factors);
    if (factors.size() < min_num_factors)
        return 0;
    for (int i = 0; i < pow_int<int>(2, factors.size()); ++i)
    {
        long long divisor = 1;
        for (int j = 0; j < factors.size(); ++j)
        {
            if ((i & (1 << j)) != 0)
                divisor *= factors[j];
        }
        if (divisors.find(divisor) == divisors.end())
            divisors.insert(divisor);
    }
    return divisors.size();
}

void euler::SolveP012()
{
    const int divisor_target = 500;
    int current_max = 0;
    long long target;
    for (int i = 1;; ++ i)
    {
        target = i * (i + 1) / 2;
        int num = GetNumDivisors(target, 9);
        if (num > current_max)
        {
            current_max = num;
            cout << "New max: " << num << endl;
        }

        //cout << target << ": " << num << endl;
        if (num > divisor_target)
            break;
    }

    long long solution = target;
    cout << "P012 solution: " << solution << endl;
}