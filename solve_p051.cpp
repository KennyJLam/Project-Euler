//
// Created by KLam on 9/15/2015.
//

#include "solve_p051.h"
#include <iostream>
#include "generators/prime_generator.h"
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

namespace euler
{
    uint increment_pattern(vector<char> &pattern, uint num_wilds);
    ull sub_wilds(const vector<char>& pattern, char sub_digit);
}

uint euler::increment_pattern(vector<char> &pattern, uint num_wilds)
{
    ++pattern[0];

    auto current_size = pattern.size();
    for (uint i = 0; i <current_size; ++i)
    {
        char digit = pattern[i];
        if (digit > '*')
        {
            --num_wilds;
            pattern[i] = 0;
            if (i < current_size - 1)
                ++pattern[ i + 1];
            else
                pattern.push_back(1);
        }
        else if (digit == 10)
        {
            pattern[i] = '*';
            ++num_wilds;
        }
    }
    if (num_wilds == 0)
    {
        pattern[0] = '*';
        num_wilds = 1;
    }
    return num_wilds;
}

ull euler::sub_wilds(const vector<char>& pattern, char sub_digit)
{
    if (sub_digit == 0 && pattern.back() == '*')
        return 0;
    ull sum = 0;
    ull exp = 1;
    for (char digit : pattern)
    {
        sum += exp * (digit == '*' ? sub_digit : digit);
        exp *= 10;
    }
    return sum;
}

// A bit slow than I'd like
void euler::SolveP051()
{
    PrimeGenerator<ull> gen;
    const uint target_matches = 8;
    string match;
    vector<char> pattern;
    pattern.push_back(1);
    pattern.push_back('*');
    uint num_wilds = 1;

    for(;;)
    {
        bool exit_loop = false;
        uint num_matches = 0;
        for (char digit = 0; digit <= 9; ++digit)
        {
            ull target = sub_wilds(pattern, digit);
            if (gen.IsPrime(target))
                ++num_matches;
            if (num_matches == target_matches)
                exit_loop = true;
        }
        if (exit_loop)
            break;
        num_wilds = increment_pattern(pattern, num_wilds);
    }

    ull min_prime = 0;

    for (char digit = 0; digit <= 9; ++digit)
    {
        ull target = sub_wilds(pattern, digit);
        if (gen.IsPrime(target))
        {
            min_prime = target;
            break;
        }
    }

    ull solution = min_prime;
    cout << "P051 solution: " << solution << endl;
}
