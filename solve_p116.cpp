//
// Created by KLam on 10/27/2015.
//

#include "solve_p116.h"
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static ull recurse_blocks(ull block_size, ull row_size, map<ull,ull>& cache);
}

ull euler::recurse_blocks(ull block_size, ull row_size, map<ull,ull>& cache)
{
    auto iter = cache.find(row_size);
    if (iter != cache.end())
        return iter->second;

    ull count = 1;
    for (ull position = 0; position + block_size <= row_size; ++position)
    {
        count += recurse_blocks(block_size, row_size - block_size - position, cache);
    }

    if (cache.find(row_size) == cache.end())
        cache[row_size] = count;
    return count;
}

void euler::SolveP116()
{
    const ull row_size = 50;

    map<ull,ull> red_cache;
    ull num_red = recurse_blocks(2, row_size, red_cache) - 1;

    map<ull,ull> green_cache;
    ull num_green = recurse_blocks(3, row_size, green_cache) - 1;

    map<ull,ull> blue_cache;
    ull num_blue = recurse_blocks(4, row_size, blue_cache) - 1;

    ull solution = num_red + num_green + num_blue;
    cout << "P116 solution: " << solution << endl;
}