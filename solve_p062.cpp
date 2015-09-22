//
// Created by KLam on 9/22/2015.
//

#include "solve_p062.h"
#include <iostream>
#include <map>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP062()
{
    const uint target_perms = 5;
    map<multiset<char>,ull> index;
    map<multiset<char>,ull> min_map;
    multiset<char> match_key;

    for (ull n = 1;; ++n)
    {
        ull cube = n * n * n;
        ull temp = cube;
        multiset<char> digits;
        while (temp > 0)
        {
            digits.insert((char)(temp % 10));
            temp /= 10;
        }
        if (index.find(digits) == index.end())
        {
            index[digits] = 0;
            min_map[digits] = cube;
        }

        ++index[digits];
        if (index[digits] == target_perms)
        {
            match_key = digits;
            break;
        }
    }

    ull solution = min_map[match_key];
    cout << "P062 solution: " << solution << endl;
}