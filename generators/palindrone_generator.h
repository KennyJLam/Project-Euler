//
// Created by KLam on 9/9/2015.
//

#ifndef PROJECT_EULER_PALINDRONEGENERATOR_H
#define PROJECT_EULER_PALINDRONEGENERATOR_H

#include <cmath>
#include "../math_utils.h"

namespace euler
{
    template<typename T>
    class PalindromeGenerator
    {
    public:
        PalindromeGenerator(T initial_value = 0);
        T GetNext();
        T GetPrev();
        T current();
    private:
        T current_;
        T half_;
        unsigned int num_digits_;
        unsigned half_digits_;
        void buildPalindroneFromHalf();
    };

    template<typename T>
    PalindromeGenerator<T>::PalindromeGenerator(T initial_value) : current_(initial_value)
    {
        num_digits_ = num_digits_int(current_);
        half_digits_ = num_digits_ / 2;
        if (num_digits_ % 2 != 0)
            ++half_digits_;
        T sum = 0;
        T working_value = initial_value;
        for (int i = 0; i < half_digits_; ++i)
        {
            sum *= 10;
            sum += working_value % 10;
            working_value /= 10;
        }
        half_ = sum;
    }

    template<typename T>
    T PalindromeGenerator<T>::GetNext()
    {
        ++half_;
        if (num_digits_int(half_) > half_digits_)
        {
            if (num_digits_ % 2 == 1)
                half_ /= 10;
            else
                ++half_digits_;
            ++num_digits_;
        }
        buildPalindroneFromHalf();
        return current_;
    }

    template<typename T>
    T PalindromeGenerator<T>::GetPrev()
    {
        --half_;
        if (num_digits_int(half_) < half_digits_)
        {
            if (num_digits_ % 2 == 0)
                half_ = half_ * 10 + 9;
            else
                --half_digits_;
            --num_digits_;
        }
        buildPalindroneFromHalf();
        return current_;
    }

    template<typename T>
    void PalindromeGenerator<T>::buildPalindroneFromHalf()
    {
        T sum = 0;
        sum = half_;
        T scratch = half_;
        unsigned int built_digits = half_digits_;
        if (num_digits_ % 2 == 1)
        {
            scratch /= 10;
            --built_digits;
        }
        for (unsigned int i = 0; i < built_digits ; ++i)
        {
            sum = sum * 10 + scratch % 10;
            scratch /= 10;
        }
        current_ = sum;
        num_digits_ = num_digits_int(current_);
        half_digits_ = num_digits_ / 2;
        if (num_digits_ % 2 != 0)
            ++half_digits_;
    }

    template<typename T>
    T PalindromeGenerator<T>::current() { return current_; }
}



#endif //PROJECT_EULER_PALINDRONEGENERATOR_H
