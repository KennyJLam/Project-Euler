//
// Created by KLam on 10/9/2015.
//

#include "solve_p088.h"
#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;


void euler::SolveP088()
{
    const uint max = 12000;

    vector<uint> matches(max - 1, 2 * max);

    vector<uint> digits;
    uint match_max = 2 * max;
    for (uint num_factors = 2; pow_int(2, num_factors) <= match_max; ++num_factors)
    {
        digits.assign(num_factors, 2);
        digits[0] = 1;
        for (;;)
        {
            uint product = 1;
            uint offset = 0;
            bool end_set = false;
            do
            {
                if (offset >= num_factors)
                {
                    end_set = true;
                    break;
                }
                fill (digits.begin(), digits.begin() + offset + 1, digits[offset] + 1);
                product = accumulate(digits.begin(), digits.end(), 1ul, multiplies<uint>());
            }
            while (++offset, product > match_max);
            if (end_set)
                break;
            uint sum = accumulate(digits.begin(), digits.end(), 0ul);
            uint num_factors_with_ones = num_factors + product - sum;
            if (num_factors_with_ones <= max)
                matches[num_factors_with_ones - 2] = min(matches[num_factors_with_ones - 2], product);
        }
    }

    set<uint> match_set;
    for (uint match : matches)
    {
        match_set.insert(match);
    }

    ull solution = accumulate(match_set.begin(), match_set.end(), 0ul);
    cout << "P088 solution: " << solution << endl;
}