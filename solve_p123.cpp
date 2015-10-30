//
// Created by KLam on 10/29/2015.
//

#include "solve_p123.h"
#include <iostream>
#include <algorithm>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP123()
{
    PrimeGenerator<ull> gen;
    const ull target = 10000000000;

    ull n;
    for (n = 1;;++n)
    {
        ull prime = gen.NextPrime();
        if (n % 2 == 0)
            continue;

        ull remainder = prime * ((2 * n) % prime);
        if (remainder > target)
            break;

    }

    ull solution = n;
    cout << "P123 solution: " << solution << endl;
}