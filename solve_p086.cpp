//
// Created by KLam on 10/8/2015.
//

#include "solve_p086.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    uint recurse_pythag_num_sides(uint a, uint b, uint c, uint max_side);
}

uint euler::recurse_pythag_num_sides(uint a, uint b, uint c, uint max_side)
{
    uint smaller, bigger;
    if (a < b)
    {
        smaller = a;
        bigger = b;
    }
    else
    {
        smaller = b;
        bigger = a;
    }
    uint max_side2 = 2 * max_side;
    if (smaller > max_side2 || bigger > max_side2)
        return 0;

    uint count = 0;
    uint temp_smaller = smaller, temp_bigger = bigger;
    while (temp_smaller <= max_side && temp_bigger <= max_side2)
    {
        if (temp_bigger <= max_side)
            count += temp_smaller / 2;
        uint half_bigger = temp_bigger / 2;
        if (temp_bigger <= 2 * temp_smaller)
            count += (temp_bigger % 2 == 0 ? temp_smaller - half_bigger + 1 : temp_smaller - half_bigger);
        temp_smaller += smaller;
        temp_bigger += bigger;
    }
    uint ret1 = recurse_pythag_num_sides(a + 2 * c - 2 * b, 2 * a + 2 * c - b, 2 * a + 3 * c - 2 * b, max_side);
    uint ret2 = recurse_pythag_num_sides(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c, max_side);
    uint ret3 = recurse_pythag_num_sides(2 * b + 2 * c - a, b + 2 * c - 2 * a, 2 * b + 3 * c - 2 * a, max_side);
    return count + ret1 + ret2 + ret3;
}

void euler::SolveP086()
{
    const uint target = 1000000;

    uint max_side;
    for (max_side = 3;;++max_side)
    {
        uint count = recurse_pythag_num_sides(3, 4, 5, max_side);
        if (count > target)
            break;
    }

    ull solution =  max_side;
    cout << "P086 solution: " << solution << endl;
}
