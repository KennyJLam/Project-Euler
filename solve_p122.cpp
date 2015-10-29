//
// Created by KLam on 10/29/2015.
//

#include "solve_p122.h"
#include <iostream>
#include <algorithm>
#include <set>

#include "combinatorics_util.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static ull get_minimum_additive_chain(ull exp);
    static bool recurse_tree(ull k, vector<ull>& addends, ull max_depth);
}

ull euler::get_minimum_additive_chain(ull exp)
{
    if (exp == 1)
        return 0;
    if (exp == 2)
        return 1;

    vector<ull> addends;
    for (ull current_depth = 1;;++current_depth)
    {
        addends = { 1 };
        if (recurse_tree(exp, addends, current_depth))
            return current_depth + 1;
    }
}

bool euler::recurse_tree(ull k, vector<ull>& addends, ull max_depth)
{
    if (addends.size() - 1 > max_depth)
        return false;

    set<ull> new_addends;
    vector<ull> indices { 0, 0 };

    do
    {
        ull sum = addends[indices[0]] + addends[indices[1]];
        if (sum == k)
            return true;
        if (sum > addends.back())
            new_addends.insert(sum);
    }
    while (next_combination_rep(indices, addends.size() - 1));

    for (auto iter = new_addends.rbegin(); iter != new_addends.rend(); ++iter)
    {
        addends.push_back(*iter);
        if (recurse_tree(k, addends, max_depth))
            return true;
        addends.pop_back();
    }

    return false;
}

// There's quite a few optimizations that could be used here such as pruning and a better minimum bounds
void euler::SolveP122()
{
    const ull target = 200;

    ull sum = 0;
    for (ull k = 1; k <= target; ++k)
    {
        sum += get_minimum_additive_chain(k);
        cout << k << endl;
    }

    ull solution = sum;
    cout << "P122 solution: " << solution << endl;
}