//
// Created by Klam on 10/10/2015.
//

#include "solve_p091.h"
#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP091()
{
    const uint max_coord = 50;
    uint max_index = (max_coord + 1) * (max_coord + 1);
    ull count = 0;

    for (int s = 1; s < max_index; ++s)
    {
        for (int t = s + 1; t < max_index; ++t)
        {
            int x1 = s / (max_coord + 1);
            int y1 = s % (max_coord + 1);
            int x2 = t / (max_coord + 1);
            int y2 = t % (max_coord + 1);
            if ((x1 == 0 && y2 == y1) || (y1 == 0 && x1 == x2))
                ++count;
            else if (x1 == x2 || y2 > y1)
                continue;
            else if (x1 == 0 && y2 == 0)
                ++count;
            else if ((x1 == 0 && x2 * x2 == (y1 - y2) * y2) || (y2 == 0 && y1 * y1 == (x2 - x1) * x1))
                ++count;
            else
            {
                int side1 = x1 * x1 + y1 * y1;
                int side2 = (x2 - x1) * (x2 - x1) + (y1 - y2) * (y1 - y2);
                int side3 = x2 * x2 + y2 * y2;
                if ((side1 + side2 == side3) || (side2 + side3 == side1))
                    ++count;
            }
        }
    }

    ull solution = count;
    cout << "P091 solution: " << solution << endl;
}
