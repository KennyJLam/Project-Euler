//
// Created by KLam on 8/27/2015.
//

#ifndef PROJECT_EULER_MATH_UTIL_H
#define PROJECT_EULER_MATH_UTIL_H

#include "prime_utils.h"

namespace euler
{
    template<typename T>
    T pow_int(T base, int exp)
    {
        if (exp == 0)
            return 1;
        T result = 1;
        for (int i = 0; i < exp; ++i)
        {
            result *= base;
        }
        return result;
    }

    // This implementation is deprecated
//    template<typename T>
//    void GetDivisors(T target, std::set<T>& divisors)
//    {
//        std::vector<T> factors;
//        GetPrimeFactors(target, factors);
//
//        for (int i = 0; i < pow_int<int>(2, factors.size()); ++i)
//        {
//            T divisor = 1;
//            for (int j = 0; j < factors.size(); ++j)
//            {
//                if ((i & (1 << j)) != 0)
//                    divisor *= factors[j];
//            }
//            if (divisors.find(divisor) == divisors.end())
//                divisors.insert(divisor);
//        }
//    }

    // This implementation is much faster than the one above
    template<typename T>
    void GetDivisors(T target, std::set<T>& divisors)
    {
        for (int i = 1; i < std::sqrt(target) + 1; ++i)
        {
            if (target % i == 0)
            {
                divisors.insert(i);
                divisors.insert(target / i);
            }
        }
    }

    template<typename T>
    T GetDivisorSum(T target)
    {
        T sum = 0;
        for (int i = 1; i < std::sqrt(target) + 1; ++i)
        {
            if (target % i == 0)
            {
                sum += i;
                sum += target / i;
            }
        }
        return sum;
    }

    template<typename T>
    T Factorial(T target)
    {
        if (target == 0)
            return 1;
        T product = 1;
        for (T i = 2; i <= target; ++i)
        {
            product *= i;
        }
        return product;
    }

    template<typename T>
    T GetGcf(T a, T b)
    {
        if (a % b == 0)
            return b;
        if (b % a == 0)
            return a;
        T gcf = 1;
        double sqrt_a = std::sqrt(a) + 1;
        double sqrt_b = std::sqrt(b) + 1;
        for (int i = 1; i < sqrt_a && i < sqrt_b; ++i)
        {
            if (a % i == 0 && b % i == 0)
            {
                if (i > gcf)
                    gcf = i;
            }
        }
        return gcf;
    }
}

#endif //PROJECT_EULER_MATH_UTIL_H
