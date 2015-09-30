//
// Created by KLam on 9/30/2015.
//

#include "solve_p078.h"
#include <iostream>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// Key terms: Unrestricted Partition, Euler Transform
void euler::SolveP078()
{
    uint target_divisor = 1000000;
    ull match = 0;
    map<uint,long long> partition_map;
    partition_map[0] = 1;
    partition_map[1] = 1;

    for (ull n = 2;;++n)
    {
        long long partition_mod = 0;
        for (uint k = 1;;++k)
        {
            int coeff = k % 2 == 1 ? 1 : -1;
            long long offset = k * (3 * k - 1) / 2;
            if (offset > n)
                break;
            partition_mod += coeff * partition_map[n - offset];
            offset = k * (3 * k + 1) / 2;
            if (offset > n)
                break;
            partition_mod += coeff * partition_map[n - offset];
            partition_mod %= target_divisor;
            if (partition_mod < 0)
                partition_mod += target_divisor;
        }
        if (partition_mod == 0)
        {
            match = n;
            break;
        }
        partition_map[n] = partition_mod;
    }

    ull solution = match;
    cout << "P078 solution: " << solution << endl;
}