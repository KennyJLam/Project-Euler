//
// Created by KLam on 9/9/2015.
//

#include "solve_p030.h"
#include <set>
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP030()
{
    set<int> matches;
    for (int i = 10; i < 400000; ++i)
    {
        int sum = 0;
        int target = i;
        while (target > 0)
        {
            int digit = target % 10;
            sum += (digit * digit * digit * digit * digit);
            target /= 10;
        }

        if (sum == i)
            matches.insert(i);
    }

    int final_sum = 0;
    for (int match : matches)
    {
        final_sum += match;
    }
    int solution = final_sum;
    cout << "P030 solution: " << solution << endl;
}
