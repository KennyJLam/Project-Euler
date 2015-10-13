//
// Created by KLam on 10/13/2015.
//

#include "solve_p095.h"
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP095()
{
    const ull max = 1000000;
    vector<ll> chain_lengths(max, -1);
    chain_lengths[0] = 1;

    for(ull n = 2; n <= max; ++n)
    {
        if (chain_lengths[n - 1] >= 0)
            continue;
        map<ull, ull> chain;
        ull current = n;
        ull chain_length = 0;
        for (;;)
        {
            ull sum = 1;
            for (ull divisor = 2; divisor < sqrt(current); ++divisor)
            {
                if (current % divisor == 0)
                    sum += divisor + current / divisor;
            }
            if (is_perfect_square(current))
                sum += sqrt_perfect(current);
            if (sum > max || chain_lengths[sum - 1] >= 0)
            {
                for (auto kvp : chain)
                {
                    chain_lengths[kvp.first - 1] = 0;
                }
                break;
            }
            if (chain.find(sum) != chain.end())
            {
                ull loop_size = chain_length - chain[sum] + 2;
                for (auto kvp  : chain)
                {
                    if (kvp.second < chain[sum])
                        chain_lengths[kvp.first - 1] = 0;
                    else
                        chain_lengths[kvp.first - 1] = loop_size;
                }
                break;
            }
            chain[current] = ++chain_length;;
            current = sum;
        }
    }

    ll best_length = 0;
    ull best_min = max;

    for (ull i = 0; i < max; ++i)
    {
        ll length = chain_lengths[i];
        if (length > best_length)
        {
            best_length = length;
            best_min = i + 1;
        }
    }
    cout <<best_length << endl;
    ull solution = best_min;
    cout << "P095 solution: " << solution << endl;
}