//
// Created by KLam on 9/9/2015.
//

#include "solve_p033.h"
#include <iostream>
#include <algorithm>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

// Really sloppy.  Comparing equality of doubles
void euler::SolveP033()
{
    set<tuple<int,int> > fractions;
    for (int denom = 12; denom < 100; ++denom)
    {
        if (denom % 10 == 0)
            continue;
        for (int num = 11; num < denom; ++num)
        {
            if (num % 10 == 0)
                continue;
            if (num % 10 == denom / 10)
            {
                int new_num = num / 10;
                int new_denom = denom % 10;
                if (new_num >= new_denom)
                    continue;
                if (abs(((double)new_num) / new_denom - ((double)num) / denom) < 0.0000001)
                    fractions.insert(make_tuple(new_num, new_denom));
            }
            else if (num / 10 == denom % 10)
            {
                int new_num = num % 10;
                int new_denom = denom / 10;
                if (new_num >= new_denom)
                    continue;
                if (abs(((double)new_num) / new_denom - ((double)num) / denom) < 0.0000001)
                    fractions.insert(make_tuple(new_num, new_denom));
            }
        }
    }
    ull num_product = 1;
    ull denom_product = 1;
    for (auto fraction : fractions)
    {
        num_product *= get<0>(fraction);
        denom_product *= get<1>(fraction);
    }
    ull gcf = GetGcf(num_product, denom_product);
    ull solution = denom_product / gcf;
    cout << "P033 solution: " << solution << endl;
}
