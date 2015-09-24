//
// Created by KLam on 9/22/2015.
//

#include "solve_p064.h"
#include <iostream>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// Apparently there's a faster way to compute this on wikipedia
void euler::SolveP064()
{
    const uint max = 10000;
    uint match_count = 0;

    for (uint n = 1; n <= max; ++n)
    {
        map<tuple<ull,ull>,uint> sequence;
        if (is_perfect_square(n))
            continue;
        tuple<ull,ull> frac;
        ull subtrahend = 0;
        ull denom = 1;
        uint cycle_count;
        for(cycle_count = 0;;++cycle_count)
        {
            long long temp = -subtrahend;
            ull square = 0;
            while (temp < 0 || square < n)
            {
                temp += denom;
                square = (ull)(temp * temp);
            }
            subtrahend = (ull)(temp - denom);
            frac = make_tuple(subtrahend, denom);
            if (sequence.find(frac) != sequence.end())
                break;
            sequence[frac] = cycle_count;
            denom = (n - subtrahend * subtrahend) / denom;
        }
        uint seq_len = cycle_count - sequence[frac];
        if (seq_len % 2 == 1)
            ++match_count;
    }

    ull solution = match_count;
    cout << "P064 solution: " << solution << endl;
}