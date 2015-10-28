//
// Created by KLam on 10/28/2015.
//

#include "solve_p118.h"
#include <iostream>
#include <algorithm>
#include "generators/prime_generator.h"
#include "generators/partition_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP118()
{
    PrimeGenerator<ull> prime_gen((ull)sqrt(987654321));
    PartitionGenerator<ull> partition_gen(9);
    vector<ull> digits { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<ull> factorials { 1 };
    for (ull i = 1; i <= 9; ++i)
    {
        factorials.push_back(i * factorials.back());
    }

    ull total_count = 0;
    do
    {
        ull count = 0;
        do
        {
            ull digit_index = 0;
            bool all_primes = true;
            for (ull piece : partition_gen.partition())
            {
                ull value = 0;
                for (int i = 0; i < piece; ++i)
                {
                    value = 10 * value + digits[digit_index++];
                }
                if (!prime_gen.IsPrime(value))
                {
                    all_primes = false;
                    break;
                }
            }
            if (all_primes)
                ++count;
        }
        while(next_permutation(digits.begin(), digits.end()));

        if (count > 0)
        {
            map<ull,ull> partition_freq;
            for (ull piece : partition_gen.partition())
            {
                if (partition_freq.find(piece) == partition_freq.end())
                    partition_freq[piece] = 0;
                ++partition_freq[piece];
            }
            ull divisor = 1;
            for (auto p : partition_freq)
            {
                divisor *= factorials[p.second];
            }
            total_count += count / divisor;
        }
    }
    while(partition_gen.Next());

    ull solution = total_count;
    cout << "P118 solution: " << solution << endl;
}