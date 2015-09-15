//
// Created by KLam on 8/27/2015.
//

#ifndef PROJECT_EULER_MATH_UTIL_H
#define PROJECT_EULER_MATH_UTIL_H

#include "prime_utils.h"
#include <unordered_set>
#include <algorithm>

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

    template<typename T>
    unsigned int num_digits_int(T target)
    {
        if (target == 0)
            return 1;
        unsigned int num_digits = 0;
        while (target != 0)
        {
            ++num_digits;
            target /= 10;
        }
        return num_digits;
    }

    template<typename T>
    T rotate_int(T target, int num_digits)
    {
        if (target < 10 && num_digits == 1)
            return target;
        T mask = pow_int<T>(10, num_digits - 1);
        return (target % mask) * 10 + target / mask;
    }

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

    template<typename T>
    bool IsBinaryPalindrone(T target)
    {
        T reverse = 0;
        T scratch = target;
        while (scratch > 0)
        {
            reverse = (reverse << 1) + (scratch & 1);
            scratch >>= 1;
        }
        return reverse == target;
    }

    template<typename T>
    bool IsPanDigital(T target, int n)
    {
        std::unordered_set<char> digits;
        while (target > 0)
        {
            char digit = target % 10;
            if (digit > n || digit == 0)
                return false;
            digits.insert(digit);
            target /= 10;
        }
        return digits.size() == n;
    }

    template<typename T>
    bool AreDigitsEquals(T a, T b)
    {
        std::map<int,int> a_digits;
        std::map<int,int> b_digits;

        while (a > 0)
        {
            int digit = a % 10;
            if (a_digits.find(digit) == a_digits.end())
                a_digits[digit] = 0;
            ++a_digits[digit];
            a /= 10;
        }

        while (b > 0)
        {
            int digit = b % 10;
            if (b_digits.find(digit) == b_digits.end())
                b_digits[digit] = 0;
            ++b_digits[digit];
            b /= 10;
        }

        return a_digits.size() == b_digits.size() &&
                std::equal(a_digits.begin(), a_digits.end(), b_digits.begin());
    }
}

#endif //PROJECT_EULER_MATH_UTIL_H
