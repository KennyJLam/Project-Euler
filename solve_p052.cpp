//
// Created by KLam on 9/15/2015.
//

#include "solve_p052.h"
#include <iostream>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

namespace euler
{
    void digits_map(ull value, map<char,uint>& digits_map);
}

void euler::digits_map(ull value, map<char,uint>& digits_map)
{
    digits_map.clear();
    while (value > 0)
    {
        char digit = (char)(value % 10);
        if (digits_map.find(digit) == digits_map.end())
            digits_map[digit] = 0;
        ++digits_map[digit];
        value /= 10;
    }
}

void euler::SolveP052()
{
    const uint max_mult = 6;
    uint floor = 10;
    ull match = 0;
    for(;;)
    {
        bool found_match = false;
        uint ceiling = floor * 10 / max_mult;

        for (uint value = floor; value < ceiling; ++value)
        {
            found_match = true;
            map<char,uint> digits;
            map<char,uint> comp_digits;

            if (value == 125874)
                bool here = true;

            digits_map(value, digits);

            for (uint i = 2; i <= max_mult; ++i)
            {
                digits_map(value * i, comp_digits);
                if (digits != comp_digits)
                {
                    found_match = false;
                    break;
                }
            }
            if (found_match)
            {
                match = value;
                break;
            }
        }

        if (found_match)
            break;
        floor *= 10;
    }

    ull solution = match;
    cout << "P052 solution: " << solution << endl;
}