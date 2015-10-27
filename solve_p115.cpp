//
// Created by KLam on 10/27/2015.
//

#include "solve_p115.h"
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static ull recurse_blocks(ull min_size, ull row_size, map<ull,ull>& cache);
}

ull euler::recurse_blocks(ull min_size, ull row_size, map<ull,ull>& cache)
{
    auto iter = cache.find(row_size);
    if (iter != cache.end())
        return iter->second;

    ull count = 1;
    for (ull block_size = min_size; block_size <= row_size; ++block_size)
    {
        for (ull position = 0; position <= row_size - block_size; ++position)
        {
            ull new_size = row_size - block_size - position;
            count += recurse_blocks(min_size, new_size == 0 ? 0 : new_size - 1, cache);
        }
    }

    if (cache.find(row_size) == cache.end())
        cache[row_size] = count;
    return count;
}

void euler::SolveP115()
{
    const ull min_size = 50;
    const ull target = 1000000;
    map<ull,ull> cache;

    ull match;
    for (ull row_size = min_size;; ++row_size)
    {
        ull count = recurse_blocks(min_size, row_size, cache);
        if (count > target)
        {
            match = row_size;
            break;
        }
    }

    ull solution = match;
    cout << "P115 solution: " << solution << endl;
}