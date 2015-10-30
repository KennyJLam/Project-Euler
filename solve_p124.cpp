//
// Created by KLam on 10/30/2015.
//

#include "solve_p124.h"
#include <iostream>
#include <algorithm>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP124()
{
    const ull max = 100000;
    const ull target = 10000;
    PrimeGenerator<ull> gen;
    vector<pair<ull,ull>> radicals;

    set<ull> factors;
    for (ull n = 1; n <= max; ++n)
    {
        gen.PrimeFactors(n, factors);
        ull radical = accumulate(factors.begin(), factors.end(), 1ull, multiplies<ull>());
        radicals.push_back(make_pair(radical, n));
    }

    sort(radicals.begin(), radicals.end());

    ull solution = radicals[target - 1].second;
    cout << "P124 solution: " << solution << endl;
}