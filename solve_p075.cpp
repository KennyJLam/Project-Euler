//
// Created by KLam on 9/29/2015.
//

#include "solve_p075.h"
#include <iostream>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

namespace euler
{
    void recurse_pythag(uint a, uint b, uint c, uint max_L, map<uint,uint>& counts);
}

void euler::recurse_pythag(uint a, uint b, uint c, uint max_L, map<uint,uint>& counts)
{
    uint L = a + b + c;
    if (L > max_L)
        return;
    uint temp_L = L;
    while (temp_L <= max_L)
    {
        if (counts.find(temp_L) == counts.end())
            counts[temp_L] = 0;
        ++counts[temp_L];
        temp_L += L;
    }
    recurse_pythag(a + 2 * c - 2 * b, 2 * a + 2 * c - b, 2 * a + 3 * c - 2 * b, max_L, counts);
    recurse_pythag(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c, max_L, counts);
    recurse_pythag(2 * b + 2 * c - a, b + 2 * c - 2 * a, 2 * b + 3 * c - 2 * a, max_L, counts);
}

// Key term: Primitive Pythagorean Triplet Tree
void euler::SolveP075()
{
    uint max_L = 1500000;
    map<uint,uint> counts;

    recurse_pythag(3, 4, 5, max_L, counts);
    uint count = 0;
    for (auto p : counts)
    {
        if (p.second == 1)
            ++count;
    }

    ull solution = count;
    cout << "P075 solution: " << solution << endl;
}
