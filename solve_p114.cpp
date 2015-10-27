//
// Created by KLam on 10/27/2015.
//

#include "solve_p114.h"
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    ull recurse_blocks(ull row_size, map<ull,ull>& cache);
}

ull euler::recurse_blocks(ull row_size, map<ull,ull>& cache)
{
    auto iter = cache.find(row_size);
    if (iter != cache.end())
        return iter->second;

    ull count = 1;
    for (ull block_size = 3; block_size <= row_size; ++block_size)
    {
        for (ull position = 0; position <= row_size - block_size; ++position)
        {
            ull new_size = row_size - block_size - position;
            count += recurse_blocks(new_size == 0 ? 0 : new_size - 1, cache);
        }
    }

    if (cache.find(row_size) == cache.end())
        cache[row_size] = count;
    return count;
}

void euler::SolveP114()
{
    const ull row_size = 50;
    map<ull,ull> cache;

    ull solution = recurse_blocks(row_size, cache);
    cout << "P114 solution: " << solution << endl;
}