//
// Created by KLam on 9/29/2015.
//

#include "solve_p077.h"
#include <iostream>
#include "generators/prime_generator.h"
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// Key terms: Prime Partition, Euler Transform
void euler::SolveP077()
{
    uint max = 5000;
    map<uint,uint> prime_partitions;
    prime_partitions[1] = 0;
    map<uint,uint> prime_sums;
    PrimeGenerator<uint> gen;

    for (uint n = 2;;++n)
    {
        set<uint> prime_factors;
        gen.PrimeFactors(n, prime_factors);
        uint prime_sum = 0;
        for (uint prime_factor : prime_factors)
        {
            prime_sum += prime_factor;
        }
        prime_sums[n] = prime_sum;

        uint partition = 0;
        for (uint j = 1; j <= n - 1; ++j)
        {
            partition += prime_sums[j] * prime_partitions[n - j];
        }
        partition += prime_sums[n];
        partition /= n;
        prime_partitions[n] = partition;
        if (partition > max)
            break;
    }

    ull solution = prime_partitions.rbegin()->first;
    cout << "P077 solution: " << solution << endl;
}