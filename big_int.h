//
// Created by KLam on 9/21/2015.
//

#ifndef PROJECT_EULER_BIG_INT_H
#define PROJECT_EULER_BIG_INT_H

#include <vector>
#include <string>

namespace euler
{
    template<typename T>
    class BigInt
    {
    public:
        BigInt();
        BigInt(unsigned long long value);
        BigInt(const std::string& digits);
        BigInt(const BigInt<T>& big_int);
        void Add(T value);
        void Add(const BigInt<T>& value);
        void Multiply(T value);
        void Multiply(const BigInt<T>&  value);
        void operator+=(T value);
        void operator+=(const BigInt<T>& value);
        void operator*=(T value);
        void operator*=(const BigInt<T>& value);
        void operator=(unsigned long long  value);
        void operator=(const BigInt<T>& value);
        unsigned int ToUint() const;
        unsigned long long int ToUll() const;
        std::string ToString() const;
        const std::vector<T>& digits() const;
        const typename std::vector<T>::size_type NumDigits() const;
        ~BigInt();
    private:
        std::vector<T> digits_;
        void ripple_carry();
    };

    template<typename T>
    BigInt<T>::BigInt() : digits_(1, 0) { }

    template<typename T>
    BigInt<T>::BigInt(unsigned long long value)
    {
        operator=(value);
    }

    template<typename T>
    void BigInt<T>::operator=(unsigned long long value)
    {
        if (value == 0)
            digits_.push_back(0);
        else
        {
            while (value > 0)
            {
                digits_.push_back(value % 10);
                value /= 10;
            }
        }
    }

    template<typename T>
    void BigInt<T>::operator=(const BigInt<T>& value)
    {
        digits_ = value.digits_;
    }

    template<typename T>
    BigInt<T>::BigInt(const BigInt<T>& big_int) : digits_(big_int.digits_) { }

    template<typename T>
    BigInt<T>::BigInt(const std::string& value)
    {
        for (auto iter = value.rbegin(); iter != value.rend(); ++iter)
        {
            digits_.push_back(*iter - '0');
        }
    }

    template<typename T>
    void BigInt<T>::operator+=(T value)
    {
        Add(value);
    }

    template<typename T>
    void BigInt<T>::operator+=(const BigInt<T>& value)
    {
        Add(value);
    }

    template<typename T>
    void BigInt<T>::operator*=(T value)
    {
        Multiply(value);
    }

    template<typename T>
    void BigInt<T>::operator*=(const BigInt<T>& value)
    {
        Multiply(value);
    }

    template<typename T>
    unsigned int BigInt<T>::ToUint() const
    {
        unsigned int value = 0;
        unsigned int exp = 1;

        for (T digit : digits_)
        {
            value += exp * digit;
            exp *= 10;
        }

        return value;
    }

    template<typename T>
    unsigned long long int BigInt<T>::ToUll() const
    {
        unsigned long long value = 0;
        unsigned long long exp = 1;

        for (T digit : digits_)
        {
            value += exp * digit;
            exp *= 10;
        }

        return value;
    }

    template<typename T>
    std::string BigInt<T>::ToString() const
    {
        std::string value;

        for (auto iter = digits_.rbegin(); iter != digits_.rend(); ++iter)
        {
            value.push_back((char)(*iter + '0'));
        }

        return value;
    }

    template<typename T>
    const std::vector<T>& BigInt<T>::digits() const { return digits_; }

    template<typename T>
    const typename std::vector<T>::size_type BigInt<T>::NumDigits() const
    {
        return digits().size();
    }

    template<typename T>
    BigInt<T>::~BigInt() { }

    template<typename T>
    void BigInt<T>::Add(T value)
    {
        digits_[0] += value;

        ripple_carry();
    }

    template<typename T>
    void BigInt<T>::Add(const BigInt<T>& value)
    {
        for (unsigned int i = 0; i < value.digits_.size(); ++i)
        {
            if (i < digits_.size())
                digits_[i] += value.digits_[i];
            else
                digits_.push_back(value.digits_[i]);
        }

        ripple_carry();
    }

    template<typename T>
    void BigInt<T>::Multiply(T value)
    {
        for (unsigned int i = 0; i < digits_.size(); ++i)
        {
            digits_[i] *= value;
        }

        ripple_carry();
    }

    template<typename T>
    void BigInt<T>::Multiply(const BigInt<T>&  value)
    {
        BigInt<T> temp(0);
        for (unsigned int i = 0; i < value.NumDigits(); ++i)
        {
            for (unsigned int j = 0; j < NumDigits(); ++j)
            {
                if (i + j < temp.NumDigits())
                    temp.digits_[i + j] += value.digits_[i] * digits_[j];
                else
                    temp.digits_.push_back(value.digits_[i] * digits_[j]);
            }
        }
        temp.ripple_carry();
        digits_ = temp.digits_;
    }

    template<typename T>
    void BigInt<T>::ripple_carry()
    {
        for (unsigned int i = 0; i < digits_.size(); ++i)
        {
            if (digits_[i] >= 10)
            {
                T temp = digits_[i] / 10;
                digits_[i] %= 10;
                unsigned int offset = 1;
                while (temp > 0)
                {
                    if ((i + offset) < digits_.size())
                        digits_[i + offset] += (temp % 10);
                    else
                        digits_.push_back(temp % 10);
                    ++offset;
                    temp /= 10;
                }
            }
        }
    }

}
#endif //PROJECT_EULER_BIG_INT_H
