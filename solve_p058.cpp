//
// Created by KLam on 9/21/2015.
//

#include "solve_p058.h"
#include <iostream>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

void euler::SolveP058()
{
    const uint max_ratio = 10;
    PrimeGenerator<ull> gen;
    ull num_primes = 0;
    ull num_values = 1;

    uint n;
    for (n = 3;; n += 2)
    {
        num_values += 4;
        ull square = n * n;
        if (gen.IsPrime(square - (n - 1)))
            ++num_primes;
        if (gen.IsPrime(square - 2 * (n - 1)))
            ++num_primes;
        if (gen.IsPrime(square - 3 * (n - 1)))
            ++num_primes;

        if (max_ratio * num_primes < num_values)
            break;
    }

    ull solution = n;
    cout << "P058 solution: " << solution << endl;
}
