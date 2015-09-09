//
// Created by KLam on 9/9/2015.
//

#include "solve_p035.h"
#include <iostream>
#include "math_utils.h"
#include "prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP035()
{
    const int max = 1000000;
    PrimeGenerator<int> gen(max);
    set<int> matches;

    for (int prime : gen.primes())
    {
        int num_digits = num_digits_int(prime);
        int rotate = rotate_int(prime, num_digits);
        bool not_prime = false;
        while (prime != rotate)
        {
            if (!gen.IsPrime(rotate))
            {
                not_prime = true;
                break;
            }
            rotate = rotate_int(rotate, num_digits);
        }
        if (not_prime)
            continue;
        matches.insert(prime);
    }

    int solution = matches.size();
    cout << "P035 solution: " << solution << endl;
}