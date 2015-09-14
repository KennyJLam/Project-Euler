//
// Created by KLam on 9/10/2015.
//

#include "solve_p037.h"
#include <iostream>
#include "generators/prime_generator.h"
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP037()
{
    PrimeGenerator<ull> gen(10000);
    gen.NextPrime(10);
    const int target_count = 11;
    int count = 0;
    ull sum = 0;

    while (count < target_count)
    {
        ull prime = gen.NextPrime();
        ull build = 0;
        uint num_digits = num_digits_int(prime);
        bool not_prime = false;
        for (uint i = 0; i < num_digits - 1; ++i)
        {
            build += (prime % 10) * pow_int(10, i);
            prime /= 10;

            if (!gen.IsPrime(build) || !gen.IsPrime(prime))
            {
                not_prime = true;
                break;
            }
        }
        if (not_prime)
            continue;
        ++count;
        sum += gen.current_prime();
        cout << count << ": " << gen.current_prime() << endl;
    }

    ull solution = sum;
    cout << "P037 solution: " << solution << endl;
}