//
// Created by KLam on 8/27/2015.
//

#include "solve_p005.h"
#include <iostream>
#include <set>
#include <map>
#include "prime_utils.h"
#include "math_utils.h"

using namespace std;

void euler::SolveP005()
{
    map<int, int> union_counts;
    for (int i = 2; i <= 20; ++i)
    {
        vector<int> prime_factors;
        map<int, int> factor_counts;
        GetPrimeFactors(i, prime_factors);
        for (int factor : prime_factors)
        {
            if (factor_counts.find(factor) == factor_counts.end())
                factor_counts[factor] = 0;
            ++factor_counts[factor];
        }

        for (const pair<int, int>& key_val : factor_counts)
        {
            if (union_counts.find(key_val.first) == factor_counts.end() || union_counts[key_val.first] < key_val.second)
                union_counts[key_val.first] = key_val.second;
        }
    }

    int lcm = 1;
    for (const pair<int, int>& key_val : union_counts)
    {
        lcm *= pow_int(key_val.first, key_val.second);
    }

    int solution = lcm;
    cout << "P005 solution: " << solution << endl;
}