//
// Created by Klam on 10/11/2015.
//

#include "solve_p092.h"
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

// A bit slow.  Much quicker way is to work on sets of digits.
void euler::SolveP092()
{
    const ull max = 10000000;
    map<ull,ull> cache;
    vector<ull> scratch;

    for (ull n = 1; n < max; ++n)
    {
        if (cache.find(n) != cache.end())
            continue;
        ull current = n;
        bool found_cache = false;
        do
        {
            if (cache.find(current) != cache.end())
            {
                found_cache = true;
                break;
            }
            scratch.push_back(current);
            ull temp = current;
            current = 0;
            while (temp > 0)
            {
                ull digit = temp % 10;
                current += digit * digit;
                temp /= 10;
            }
        }
        while (current != 89 && current != 1);
        ull result = found_cache ? cache[current] : current;
        while (!scratch.empty())
        {
            cache[scratch.back()] = result;
            scratch.pop_back();
        }
    }

    ull count = 0;
    for (ull n = 1; n < max; ++n)
    {
        if (cache[n] == 89)
            ++count;
    }

    ull solution = count;
    cout << "P092 solution: " << solution << endl;
}

