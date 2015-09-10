//
// Created by KLam on 9/10/2015.
//

#include "solve_p040.h"
#include "math_utils.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int euler::GetChampDigit(int digit)
{
    int mag = 0;
    int lower, upper = 1;
    do
    {
        ++mag;
        lower = upper;
        upper = lower + mag * 9 * pow_int(10, mag - 1);
    }
    while (digit >= upper);
    int number = pow_int(10, mag - 1) + (digit - lower) / mag;
    int pos = digit - ((number - pow_int(10, mag - 1)) * mag + lower);
    for (int i = 0; i < mag - pos - 1; ++i)
    {
        number /= 10;
    }
    return number % 10;
}

void euler::SolveP040()
{
    int power = 6;
    int product = 1;
    for (int i = 0; i <= power; ++i)
    {
        product *= GetChampDigit(pow_int(10, i));
    }
    int solution = product;
    cout << "P040 solution: " << solution << endl;
}