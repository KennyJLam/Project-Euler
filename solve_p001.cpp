//
// Created by KLam on 8/26/2015.
//

#include "solve_p001.h"
#include <iostream>

using namespace std;

// Gets the sum of all multiples from 0 to max
int euler::MultipleSum(int multiple, int max)
{
    int sum = 0;
    for (int i = 0; i < max; i += multiple)
    {
        sum += i;
    }
    return sum;
}

void euler::SolveP001()
{
    const int kMax = 1000;
    int multiple3_sum = MultipleSum(3, kMax);
    int multiple5_sum = MultipleSum(5, kMax);
    int multiple15_sum = MultipleSum(15, kMax);
    int solution = multiple3_sum + multiple5_sum - multiple15_sum;
    cout << "P001 solution: " << solution << endl;
}