//
// Created by KLam on 9/9/2015.
//

#include "solve_p036.h"
#include <iostream>
#include "math_utils.h"
#include "generators/palindrone_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP036()
{
    const uint max = 1000000;
    PalindromeGenerator<uint> gen;
    uint sum = 0;
    uint target = gen.GetNext();
    while (target < max)
    {
        if (IsBinaryPalindrone(target))
            sum += target;
        target = gen.GetNext();
    }

    int solution = sum;
    cout << "P036 solution: " << solution << endl;
}