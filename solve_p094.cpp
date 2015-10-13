//
// Created by KLam on 10/13/2015.
//

#include "solve_p094.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    ull recurse_triangles(ll a, ll b, ll c, ll max_perimeter);
}

ull euler::recurse_triangles(ll a, ll b, ll c, ll max_perimeter)
{
    ull sum = 0;
    if (2 * (a + c) > max_perimeter && 2 * (b + c) > max_perimeter)
        return 0;
    if (2 * (a + c) <= max_perimeter && abs(c - 2 * a) == 1)
        sum += 2 * (a + c);
    if (2 * (b + c) <= max_perimeter && abs(c - 2 * b) == 1)
        sum += 2 * (b + c);
    ull ret1 = recurse_triangles(a + 2 * c - 2 * b, 2 * a + 2 * c - b, 2 * a + 3 * c - 2 * b, max_perimeter);
    ull ret2 = recurse_triangles(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c, max_perimeter);
    ull ret3 = recurse_triangles(2 * b + 2 * c - a, b + 2 * c - 2 * a, 2 * b + 3 * c - 2 * a, max_perimeter);

    return sum + ret1 + ret2 + ret3;
}

void euler::SolveP094()
{
    const ull max = 1000000000;

    ull solution = recurse_triangles(3, 4, 5, max);
    cout << "P094 solution: " << solution << endl;
}