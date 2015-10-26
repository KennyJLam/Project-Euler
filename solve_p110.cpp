//
// Created by KLam on 10/26/2015.
//

#include "solve_p110.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include "generators/prime_generator.h"
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP110()
{
    const ull target = 4000000;
    ull n;
    PrimeGenerator<ull> gen;
//    for (n = 2;;++n)
//    {
//        map<ull,ull> prime_factors = gen.PrimeFactorFreq(n);
//        ull num_factors = 1;
//        for (const auto& p : prime_factors)
//        {
//            num_factors *= (2 * p.second) + 1;
//        }
//        ull num_solutions = (num_factors + 1) / 2;
//
//        if (num_solutions > target)
//            break;
//    }
//    ull best_val = n;

    vector<ull> primes;
    ull ceiling = 1;
    ull log_ceiling = 0;
    double log_temp = 2 * log(target);
    while (log_temp > 3)
    {
        primes.push_back(gen.NextPrime());
        log_ceiling += log(gen.current_prime());
        log_temp -= log(3);
    }

    vector<ull> exp_limits;
    //double log_ceiling = log(ceiling);
    for (ull i = 0; i < primes.size(); ++i)
    {
        exp_limits.push_back((ull)(log_ceiling / accumulate(primes.begin(), primes.begin() + i + 1, 0.0, [](double sum, ull val)
        { return sum + log(val); })));
    }

    ull best_val = numeric_limits<ull>::max();
    vector<ull> prime_freqs(primes.size(), 0);
    ull ct = 0;
    for (;;)
    {
        bool exit_loop = true;
        for (ll i = prime_freqs.size() - 1; i >= 0; --i)
        {
            if (prime_freqs[i] < exp_limits[i] && (i == 0 || prime_freqs[i] < prime_freqs[i - 1]))
            {
//                ull num_divisors = accumulate(prime_freqs.begin(), prime_freqs.end(), 1ull,
//                    [&] (ull product, ull freq) { return product * (2 * freq + 1); });
                if (ct % 1000000 == 0)
                {
                    for (ull freq : prime_freqs)
                    {
                        cout << freq << " ";
                    }
                    cout << endl;
                    ct = 0;
                }
                ++ct;
                ull num_divisors = 1;
                for (ull j = 0; j < prime_freqs.size(); ++j)
                {
                    num_divisors *= (2 * prime_freqs[j] + 1);
                }
                if (num_divisors > 2 * target - 1)
                {
                    ull candidate = 1;
                    for (ull j = 0; j < prime_freqs.size(); ++j)
                    {
                        candidate *= pow_int(primes[j], prime_freqs[j]);
                        if (log(candidate) > log(best_val))
                            break;
                    }
                    if (candidate < best_val)
                        best_val = candidate;
                }
                ++prime_freqs[i];
                fill(prime_freqs.begin() + i + 1, prime_freqs.end(), 0);
                exit_loop = false;
                break;
            }
        }
        if (exit_loop || prime_freqs[0] > 30)
            break;
    }

    ull solution = best_val;
    cout << "P110 solution: " << solution << endl;
}