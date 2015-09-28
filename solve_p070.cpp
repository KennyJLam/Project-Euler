//
// Created by KLam on 9/28/2015.
//

#include "solve_p070.h"
#include <iostream>
#include <map>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

// First attempt takes about 2 minutes.  Too long.  Using some hints from the forum,
// we can surmise that the answer must be the product of two prime numbers.  This
// greatly reduces the search space.  Still takes about 25 seconds though.
void euler::SolveP070()
{
    const ull max = 10000000;
    PrimeGenerator<ull> gen(max / 2);
    set<ull> prior_matches;
    double min_ratio = max;
    ull best_n = 0;

    for (ull prime : gen.primes())
    {
        if (prime > max / 2)
            break;
        for (ull prime2 : gen.primes())
        {
            ull n = prime * prime2;
            if (n > max)
                break;

            ull totient = (prime - 1) * (prime2 - 1);

            multiset<ull> n_map, totient_map;
            ull temp = n, temp2 = totient;
            while (temp > 0)
            {
                n_map.insert(temp % 10);
                temp /= 10;
            }
            while (temp2 > 0)
            {
                totient_map.insert(temp2 % 10);
                temp2 /= 10;
            }
            if (n_map == totient_map)
            {
                prior_matches.insert(n);
                double ratio = ((double) n) / totient;
                if (ratio < min_ratio)
                {
                    min_ratio = ratio;
                    best_n = n;
                }
            }
        }
    }

    ull solution = best_n;
    cout << "P070 solution: " << solution << endl;
}

/*
void euler::SolveP070()
{
    const ull max = 10000000;
    PrimeGenerator<ull> gen(10000);
    map<ull,ull> totients;
    set<ull> prior_matches;
    double min_ratio = max;
    ull best_n = 0;

    for (ull n = 2; n < max; ++n)
    {
        if (gen.IsPrime(n))
        {
            totients[n] = n - 1;
            continue;
        }
        else
        {
            for (ull prime : gen.primes())
            {
                if (n % prime == 0)
                {
                    totients[n] = totients[prime] * totients[n / prime];
                    break;
                }
            }
        }
        ull totient = totients[n];

        multiset<ull> n_map, totient_map;
        ull temp = n, temp2 = totient;
        while (temp > 0)
        {
            n_map.insert(temp % 10);
            temp /= 10;

        }
        while (temp2 > 0)
        {
            totient_map.insert(temp2 % 10);
            temp2 /= 10;
        }
        if (n_map == totient_map)
        {
            prior_matches.insert(n);
            double ratio = ((double) n) / totient;
            if (ratio < min_ratio)
            {
                min_ratio = ratio;
                best_n = n;
            }
        }
    }

    ull solution = best_n;
    cout << "P070 solution: " << solution << endl;
}
 */