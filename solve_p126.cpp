//
// Created by KLam on 10/30/2015.
//

#include "solve_p126.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static ull get_num_cubes(ull a, ull b, ull c, ull layer);
    static bool has_solution(ull a, ull b, ull layer, ull num_cubes);
}

ull euler::get_num_cubes(ull a, ull b, ull c, ull layer)
{
    return 2 * (a*b + b*c + a*c) + 4 * max(0ull, layer - 1) * (a + b + c) + 8 * max(0ull, layer - 2) * (layer - 1) / 2;
}

bool euler::has_solution(ull a, ull b, ull layer, ull num_cubes)
{
    return ((num_cubes - 2 * (a*b) - 4 * max(0ull, layer - 1) * (a + b) - 8 * max(0ull, layer - 2) * (layer - 1) / 2)
           % (2 * (a + b) + 4 * max(0ull, layer - 1))) == 0;
}

void euler::SolveP126()
{
    const ull target = 1000;

    ull n;
    for (n = 6;;++n)
    {
        ull count = 0;
        ull layer_ceiling;
        for (layer_ceiling = 1; get_num_cubes(1, 1, 1, layer_ceiling) <= n; ++layer_ceiling);
        --layer_ceiling;

        for (ull layer = 1; layer <= layer_ceiling; ++layer)
        {
            ull a, b, c;
            for (a = 1;get_num_cubes(a, a, a, layer) <= n;++a)
            {
                for (b = a;get_num_cubes(a, b, b, layer) <= n;++b)
                {
                    if (has_solution(a, b, layer, n))
                        ++count;
                }
            }
        }
        if (count == target)
            break;
    }

    ull solution = n;
    cout << "P126 solution: " << solution << endl;
}