//
// Created by KLam on 9/28/2015.
//

#include "solve_p071.h"
#include <iostream>
#include <map>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP071()
{
    const uint max_denom = 1000000;
    const uint target_num = 3;
    const uint target_denom = 7;
    uint denom_floor = max_denom / target_denom * target_denom;

    ull best_num = 0, best_denom = 1;

    for (ull d = 2; d <= max_denom; ++d)
    {
        if (target_denom % d == 0 || d % target_denom == 0)
            continue;
        ull n = d * target_num / target_denom;
        if (n != 0 && n * best_denom > d * best_num)
        {
            best_num = n;
            best_denom = d;
        }
    }


    ull solution = best_num;
    cout << "P071 solution: " << solution << endl;
}