//
// Created by KLam on 10/27/2015.
//

#include "solve_p117.h"
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static ull recurse_blocks(ull row_size, map<ull,ull>& cache);
}

ull euler::recurse_blocks(ull row_size, map<ull,ull>& cache)
{
    auto iter = cache.find(row_size);
    if (iter != cache.end())
        return iter->second;

    ull count = 1;
    for (ull block_size = 2; block_size <= 4; ++block_size)
    {
        for (ull position = 0; position + block_size <= row_size; ++position)
        {
            count += recurse_blocks(row_size - block_size - position, cache);
        }
    }

    if (cache.find(row_size) == cache.end())
        cache[row_size] = count;
    return count;
}

void euler::SolveP117()
{
    const ull row_size = 50;

    map<ull,ull> cache;
    ull count = recurse_blocks(row_size, cache);

    ull solution = count;
    cout << "P117 solution: " << solution << endl;
}