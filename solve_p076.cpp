//
// Created by KLam on 9/29/2015.
//

#include "solve_p076.h"
#include <iostream>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// Key term: Partition Function (Number Theory)
void euler::SolveP076()
{
    uint target = 100;
    map<uint,ull> partition_map;
    partition_map[0] = 1;
    partition_map[1] = 1;

    for (uint n = 2; n <= target; ++n)
    {
        ull sum = 0;
        for (uint k = 1;;++k)
        {
            int coeff = k % 2 == 1 ? 1 : -1;
            uint offset = k * (3 * k - 1) / 2;
            if (offset > n)
                break;
            sum += coeff * partition_map[n - offset];
            offset = k * (3 * k + 1) / 2;
            if (offset > n)
                break;
            sum += coeff * partition_map[n - offset];
        }
        partition_map[n] = sum;
    }

    ull solution = partition_map[target] - 1;
    cout << "P076 solution: " << solution << endl;
}