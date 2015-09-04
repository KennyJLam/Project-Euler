//
// Created by KLam on 8/27/2015.
//

#ifndef PROJECT_EULER_PRIME_UTILS_H
#define PROJECT_EULER_PRIME_UTILS_H

#include <vector>
#include <map>
#include <set>
#include <cmath>

namespace euler
{
    // Appends and returns the next prime number given a sequence of prime numbers in ascending order
    template <typename T>
    T GetNextPrime(std::vector<T>& primes)
    {
        if (primes.empty())
        {
            primes.push_back(2);
            return 2;
        }

        for (T i = primes.back() == 2 ? 3 : primes.back() + 2;; i += 2)
        {
            T i_sqrt = (T)std::floor(std::sqrt(i));
            bool divisible = false;
            for (T prime : primes)
            {
                if (prime > i_sqrt)
                    break;
                if (i % prime == 0)
                {
                    divisible = true;
                    break;
                }
            }
            if (divisible)
                continue;
            primes.push_back(i);
            return i;
        }
    }

    template<typename T>
    void GetPrimeFactors(T target, std::vector<T> &factors)
    {
        std::vector<T> primes;
        while (target != 1)
        {
            GetNextPrime(primes);
            while(target % primes.back() == 0 && target != 1)
            {
                factors.push_back(primes.back());
                target /= primes.back();
            }
        }
    }

    template<typename T>
    void GetPrimeFactorCounts(T target, std::map<T, int> &factor_counts)
    {
        std::vector<T> primes;
        while (target != 1)
        {
            GetNextPrime(primes);
            T prime = primes.back();
            while(target % prime == 0 && target != 1)
            {
                if (factor_counts.find(prime) == factor_counts.end())
                    factor_counts[prime] = 0;
                ++factor_counts[prime];
                target /= primes.back();
            }
        }
    }

    template<typename T>
    void GetPrimeFactorSet(T target, std::set<T> &factor_set)
    {
        int total_count;
        return GetPrimeFactorSet(target, factor_set, total_count);
    }

    template<typename T>
    void GetPrimeFactorSet(T target, std::set<T> &factor_set, int& total_count)
    {
        std::vector<T> primes;
        total_count = 0;
        while (target != 1)
        {
            GetNextPrime(primes);
            T prime = primes.back();
            while(target % prime == 0 && target != 1)
            {
                if (factor_set.find(prime) == factor_set.end())
                    factor_set.insert(prime);
                target /= primes.back();
                ++total_count;
            }
        }
    }
}

#endif //PROJECT_EULER_PRIME_UTILS_H
