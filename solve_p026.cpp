//
// Created by KLam on 9/1/2015.
//

#include "solve_p026.h"
#include <iostream>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP026()
{
    const uint max = 1000;

    int max_repeats = 0;
    uint max_val = 0;
    uint i;
    for (i = 2; i < max; ++i)
    {
        int repeats = 0;
        int residual = 1;
        map<int,int> residuals;
        do
        {
            residuals[residual] = repeats;
            residual = (residual * 10) % i;
            if (residual == 0)
            {
                repeats = 0;
                break;
            }
            ++repeats;
        }
        while (residuals.find(residual) == residuals.end());
        if (repeats > 0)
            repeats -= residuals[residual];

        if (repeats > max_repeats)
        {
            max_val = i;
            max_repeats = repeats;
        }
    }

    uint solution = max_val;
    cout << "P026 solution: " << solution << endl;
}
