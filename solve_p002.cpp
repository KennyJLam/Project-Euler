//
// Created by KLam on 8/26/2015.
//

#include "solve_p002.h"
#include <iostream>

using namespace std;

void euler::SolveP002()
{
    long long sum = 0;
    long long current = 1;
    long long prev = 0;
    const long long kMax = 4000000;

    while (current < kMax)
    {
        if (current % 2 == 0)
            sum += current;
        long long temp = current;
        current += prev;
        prev = temp;
    }

    long long solution = sum;
    cout << "P002 solution: " << solution << endl;
}
