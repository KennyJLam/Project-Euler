//
// Created by KLam on 8/28/2015.
//

#include "solve_p014.h"
#include "math_utils.h"
#include <iostream>

using namespace std;

int euler::GetCollatzLength(long long seed, map<long long,int>& table)
{
    if (table.find(seed) != table.end())
        return table[seed];

    int length;
    if (seed == 1)
        length = 1;
    else if (seed % 2 == 0)
        length = GetCollatzLength(seed / 2, table) + 1;
    else
        length = GetCollatzLength(3 * seed + 1, table) + 1;

    table[seed] = length;
    return length;
}

void euler::SolveP014()
{
    const int seed_max = 1000000;
    int max = 0;
    long long best_seed = 1;
    map<long long,int> collatz_table;
    for (long long seed = 1; seed < seed_max; ++seed)
    {
        //cout << seed << endl;
        int length = euler::GetCollatzLength(seed, collatz_table);
        if (length > max)
        {
            best_seed = seed;
            max = length;
        }
    }

    long long solution = best_seed;
    cout << "P014 solution: " << solution << endl;
}
