//
// Created by KLam on 8/26/2015.
//

#include "solve_p004.h"
#include "prime_utils.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using euler::PalindromeGenerator;

PalindromeGenerator::PalindromeGenerator(int initial_value) : current_(initial_value)
{
    num_digits_ = (int)floor(log10(current_)) + 1;
    used_digits_ = num_digits_ / 2;
    if (num_digits_ % 2 != 0)
        ++used_digits_;
    int sum = 0;
    int working_value = initial_value;
    for (int i = 0; i < used_digits_; ++i)
    {
        sum *= 10;
        sum += working_value % 10;
        working_value /= 10;
    }
    half_ = sum;
}

int PalindromeGenerator::GetPrev()
{
    --half_;
    int sum = 0;
    if (num_digits_ % 2 == 0)
    {
        for (int i = 0; i < used_digits_ ; ++i)
        {
            int digit = (half_ / pow10(used_digits_ - i - 1)) % 10;
            sum += digit * (pow10(num_digits_ - i - 1) + pow10(i));
        }
    }
    else
    {
        int i;
        for (i = 0; i < used_digits_ - 1 ; ++i)
        {
            int digit = (half_ / pow10(used_digits_ - i - 1)) % 10;
            sum += digit * (pow10(num_digits_ - i - 1) + pow10(i));
        }
        int digit = (half_ / pow10(used_digits_ - i - 1)) % 10;
        sum += digit * pow10(num_digits_ - i - 1);
    }

    current_ = sum;
    num_digits_ = (int)floor(log10(current_)) + 1;
    used_digits_ = num_digits_ / 2;
    if (num_digits_ % 2 != 0)
        ++used_digits_;
    return current_;
}

int PalindromeGenerator::pow10(int exponent)
{
    int product = 1;
    for (int i = 0; i < exponent; ++i)
    {
        product *= 10;
    }
    return product;
}

unsigned int euler::Pow2(int exponent)
{
    unsigned int product = 1;
    for (int i = 0; i < exponent; ++i)
    {
        product *= 2;
    }
    return product;
}

int PalindromeGenerator::current() { return current_; }

bool euler::CanBe3Factored(int target, int& result1, int& result2)
{
    vector<int> factors;
    GetPrimeFactors(target, factors);
    for (int i = 0; i < factors.size(); ++i)
    {
        int factor = factors[i];
        if (factor >= 1000)
            return false;
    }
    unsigned int i = 1;
    unsigned int limit = Pow2(factors.size());
    while (i < limit)
    {
        int factor1 = 1;
        int factor2 = 1;
        for (int j = 0; j < factors.size(); ++j)
        {
            if ((i & (1 << j)) == 0)
                factor1 *= factors[j];
            else
                factor2 *= factors[j];
        }
        if (factor1 >= 100 && factor1 < 1000 && factor2 >= 100 && factor2 < 1000)
        {
            result1 = factor1;
            result2 = factor2;
            return true;
        }
        ++i;
    }

    return false;
}

// This was done in a much more complicated manner than necessary
void euler::SolveP004()
{
    PalindromeGenerator gen(1000 * 1000 - 1);
    int factor1 = 0, factor2 = 0;
    for (;;)
    {
        int palindrome = gen.GetPrev();
        //cout << palindrome << endl;
        if (CanBe3Factored(palindrome, factor1, factor2))
            break;
    }
    int solution = gen.current();
    cout << "P004 solution: " << solution << endl;
}