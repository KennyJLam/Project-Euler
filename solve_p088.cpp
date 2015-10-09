//
// Created by KLam on 10/9/2015.
//

#include "solve_p088.h"
#include <iostream>
#include <set>
#include <vector>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;


void euler::SolveP088()
{
    const uint max = 12000;

    set<uint> matches { 4 };

    vector<uint> digits;
    for (uint k = 3; k <= max; ++k)
    {
        digits.clear();
        uint min = 2 * k;

        for (uint num_factors = 1; pow_int(2, num_factors) < k; ++num_factors)
        {
            for (uint i : digits)
            {
                digits[i] = 2;
            }
            digits.push_back(2);

            for (;;)
            {
                uint product = 1;
                for (uint digit : digits)
                {
                    product *= digit;
                }
                if (product >= k)
                {

                    continue;
                }
                uint sum = 0;
                for (uint digit : digits)
                {
                    sum += digit;
                }
                ++digits.front();
                break;
            }
        }


    }

    ull sum = 0;
    for (uint match : matches)
    {
        sum += match;
    }
    ull solution = sum;
    cout << "P088 solution: " << solution << endl;
}