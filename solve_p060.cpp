//
// Created by KLam on 9/21/2015.
//

#include "solve_p060.h"
#include <iostream>
#include "generators/prime_generator.h"
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

namespace euler
{
    bool is_concat_prime(ull prime1, ull prime2, PrimeGenerator<ull>& gen);
}

bool euler::is_concat_prime(ull prime1, ull prime2, PrimeGenerator<ull>& gen)
{
    uint prime1_digits = num_digits_int(prime1);
    uint prime2_digits = num_digits_int(prime2);

    return gen.IsPrime(prime1 * pow_int(10, prime2_digits) + prime2) &&
            gen.IsPrime(prime2 * pow_int(10, prime1_digits) + prime1);
}

// This is rather slow and there isn't really any guarantee that this is the actual minimum sum
void euler::SolveP060()
{
    const uint max_family_size = 5;
    set<ull>* match = nullptr;
    PrimeGenerator<ull> gen;
    vector<set<ull>*> families;

    for (;;)
    {
        bool found_match = false;
        ull prime = gen.NextPrime();
        auto current_size = families.size();

        for (uint i = 0; i < current_size; ++i)
        {
            set<ull>* family = families[i];
            bool is_family_prime = true;
            for (ull prime2 : *family)
            {
                if (!is_concat_prime(prime, prime2, gen))
                {
                    is_family_prime = false;
                    break;
                }
            }
            if (is_family_prime)
            {
                set<ull>* new_family = new set<ull>(*family);
                new_family->insert(prime);
                families.push_back(new_family);
                if (new_family->size() >= max_family_size)
                {
                    match = new_family;
                    found_match = true;
                    break;
                }
            }
        }

        if (found_match)
            break;

        for (ull prime2 : gen.primes())
        {
            if (prime2 >= prime)
                break;
            if (is_concat_prime(prime, prime2, gen))
            {
                set<ull>* family = new set<ull>();
                family->insert(prime);
                family->insert(prime2);
                families.push_back(family);
            }
        }
    }

    ull sum = 0;
    for (ull prime : *match)
    {
        sum += prime;
    }

    ull solution = sum;
    cout << "P060 solution: " << solution << endl;

    for (auto family : families)
    {
        delete family;
    }
}
