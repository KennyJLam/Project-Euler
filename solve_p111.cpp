//
// Created by KLam on 10/26/2015.
//

#include "solve_p111.h"
#include <iostream>
#include <algorithm>
#include "generators/prime_generator.h"
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP111()
{
    const ull num_digits = 10;
    ull ceiling = pow_int(10ull, num_digits);
    PrimeGenerator<ull> gen(pow_int(10ull, num_digits / 2 + num_digits % 2));
    vector<ull> matches;
    ull floor = pow_int(10ull, num_digits - 1);

    for (uint repeat_digit = 0; repeat_digit <= 9; ++repeat_digit)
    {
        for (ll num_repeats = num_digits - 1; num_repeats >= 0; --num_repeats)
        {
            bool found_digits = false;
            ull num_free = num_digits - num_repeats;
            for (uint free = 0; free < pow_int(10ull, num_free); ++free)
            {
                vector<ll> free_digits;
                vector<uint> positions(num_free, 0);
                ull check = free;
                bool has_redundant = false;

                while (check > 0)
                {
                    ull digit = check % 10;
                    if (digit == repeat_digit)
                    {
                        has_redundant = true;
                        break;
                    }
                    free_digits.push_back(digit);
                    check /= 10;
                }
                if (repeat_digit == 0 && (free_digits.size() < num_free))
                    has_redundant = true;
                if (has_redundant)
                    continue;
                while (free_digits.size() < num_free)
                {
                    free_digits.push_back(0);
                }

                for (ull i = 1; i < positions.size(); ++i)
                {
                    positions[i] = positions[i - 1] + 1;
                }

                for (;;)
                {
                    ull candidate = 0;
                    ll free_pos = positions.size() - 1;
                    for (ll j = 0; j < num_digits; ++j)
                    {
                        ll digit = find(positions.begin(), positions.end(), j) != positions.end() ? free_digits[free_pos--] : repeat_digit;
                        candidate = 10 * candidate + digit;
                    }

                    if (candidate >= floor && gen.IsPrime(candidate))
                    {
                        found_digits = true;
                        matches.push_back(candidate);
                    }
                    bool exit_loop = true;
                    for (ll j = positions.size() - 1; j >= 0; --j)
                    {
                        if (positions[j] < num_digits - (positions.size() - j))
                        {
                            exit_loop = false;
                            ++positions[j];
                            for (ll k = j + 1; k < positions.size();++k)
                            {
                                positions[k] = positions[k - 1] + 1;
                            }
                            break;
                        }
                    }
                    if (exit_loop)
                        break;
                }
            }
            if (found_digits)
                break;
        }
    }

    ull sum = accumulate(matches.begin(), matches.end(), 0ull);
    ull solution = sum;
    cout << "P111 solution: " << solution << endl;
}