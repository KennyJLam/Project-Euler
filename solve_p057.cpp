//
// Created by KLam on 9/21/2015.
//

#include "solve_p057.h"
#include <iostream>
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

void euler::SolveP057()
{
    const uint max_iterations = 1000;
    BigInt<ull> big_int1(1), big_int2(1);
    BigInt<ull>* num = &big_int1;
    BigInt<ull>* denom = &big_int2;
    uint num_matches = 0;

    for (uint i = 0; i < max_iterations; ++i)
    {
        *num += *denom;

        BigInt<ull>* temp = denom;
        denom = num;
        num = temp;

        *num += *denom;

        if (num->NumDigits() > denom->NumDigits())
            ++num_matches;
    }

    ull solution = num_matches;
    cout << "P057 solution: " << solution << endl;
}
