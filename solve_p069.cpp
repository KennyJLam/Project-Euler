//
// Created by Klam on 9/26/2015.
//

#include "solve_p069.h"
#include <iostream>
#include "generators/prime_generator.h"


typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP069()
{
    const uint max = 1000000;
    PrimeGenerator<uint> gen;

    ull value = 1;
    ull next_value = 1;
    while (next_value <= max)
    {
        value = next_value;
        next_value *= gen.NextPrime();
    }

    ull solution = value;
    cout << "P069 solution: " << solution << endl;
}
