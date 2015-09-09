//
// Created by KLam on 9/9/2015.
//

#include "solve_p034.h"
#include <iostream>
#include <unordered_map>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

// Quite slow
void euler::SolveP034()
{
    unordered_map<int,int> factorials;
    set<ull> matches;
    for (int i = 0; i <= 9; ++i)
    {
        factorials[i] = Factorial(i);
    }
    for (ull i = 10; i < 9999999; ++ i)
    {
        ull sum = 0;
        ull scratch = i;
        while (scratch > 0)
        {
            sum += factorials[scratch % 10];
            scratch /= 10;
        }
        if (sum == i)
            matches.insert(i);
    }
    ull sum = 0;
    for (ull match : matches)
    {
        sum += match;
    }
    ull solution = sum;
    cout << "P034 solution: " << solution << endl;
}