//
// Created by KLam on 9/28/2015.
//

#include "solve_p074.h"
#include <iostream>
#include <set>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// Rather slow
void euler::SolveP074()
{
    const uint max = 1000000;
    const uint target_length = 60;

    uint factorials[10];
    factorials[0] = 1;
    uint factorial = 1;
    for (uint n = 1; n <= 9; ++n)
    {
        factorial *= n;
        factorials[n] = factorial;
    }

    uint count = 0;
    for (uint n = 3; n < max; ++n)
    {
        set<ull> sums;
        ull term = n;
        sums.insert(n);
        for (;;)
        {
            ull sum = 0;
            while (term > 0)
            {
                sum += factorials[term % 10];
                term /= 10;
            }
            if (sums.find(sum) != sums.end())
                break;
            sums.insert(sum);
            term = sum;
        }
        if (sums.size() == target_length)
            ++count;
    }

    ull solution = count;
    cout << "P074 solution: " << solution << endl;
}
