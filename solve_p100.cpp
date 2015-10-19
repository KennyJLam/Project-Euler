//
// Created by KLam on 10/16/2015.
//

#include "solve_p100.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP100()
{
    const ull floor = 1000000000000;

    ull t_floor = 2 * floor + 1;
    ull t_num_discs = 1, t_num_blue = 1;

    while (t_num_discs <= t_floor)
    {
        ull temp = t_num_discs;
        t_num_discs = t_num_discs + 2 * t_num_blue;
        t_num_blue = t_num_blue + temp;
    }

    ull solution = (t_num_blue + 1) / 2;
    cout << "P100 solution: " << solution << endl;
}
