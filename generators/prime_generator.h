//
// Created by KLam on 9/8/2015.
//

#ifndef PROJECT_EULER_PRIME_GENERATOR_H
#define PROJECT_EULER_PRIME_GENERATOR_H

#include <cmath>
#include <set>

namespace euler
{
    template<typename T>
    class PrimeGenerator
    {
    public:
        PrimeGenerator(T floor = 0);
        T NextPrime();
        T NextPrime(T floor);
        bool IsPrime(T value);
        const std::set<T>& primes() const;
        const T current_prime() const;
        ~PrimeGenerator();
    private:
        std::set<T> primes_;
        T generate_new_prime();
        void generate_new_primes(T floor);
        T current_prime_;
        T max_prime_;
    };

    // Ensures that all prime numbers less than or equal to floor are generated
    template<typename T>
    PrimeGenerator<T>::PrimeGenerator(T floor) : current_prime_(0), max_prime_(0)
    {
        generate_new_primes(floor);
    }

    template<typename T>
    PrimeGenerator<T>::~PrimeGenerator() { }

    template<typename T>
    const std::set<T>& PrimeGenerator<T>::primes() const { return primes_; }

    template<typename T>
    const T PrimeGenerator<T>::current_prime() const { return current_prime_; }

    template<typename T>
    T PrimeGenerator<T>::NextPrime()
    {
        return NextPrime(current_prime_);
    }

    // Returns the first prime strictly greater than floor
    template<typename T>
    T PrimeGenerator<T>::NextPrime(T floor)
    {
        if (floor >= max_prime_)
            generate_new_primes(floor);
        return current_prime_ = *(primes_.upper_bound(floor));
    }

    template<typename T>
    bool PrimeGenerator<T>::IsPrime(T value)
    {
        if (value > max_prime_)
            generate_new_primes(value);
        return primes_.find(value) != primes_.end();
    }

    template<typename T>
    void PrimeGenerator<T>::generate_new_primes(T floor)
    {
        T i = max_prime_;
        while (i <= floor)
        {
            i = generate_new_prime();
        }
        max_prime_ = i;
    }

    template<typename T>
    T PrimeGenerator<T>::generate_new_prime()
    {
        if (primes_.empty())
        {
            primes_.insert(2);
            return 2;
        }

        T i = *primes_.rbegin();
        i += (i == 2 ? 1 : 2);
        for (;; i += 2)
        {
            T i_sqrt = (T)std::floor(std::sqrt(i));
            bool divisible = false;
            for (T prime : primes_)
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
            primes_.insert(i);
            return i;
        }
    }
}

#endif //PROJECT_EULER_PRIME_GENERATOR_H
