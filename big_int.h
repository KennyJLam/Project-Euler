//
// Created by KLam on 9/21/2015.
//

#ifndef PROJECT_EULER_BIG_INT_H
#define PROJECT_EULER_BIG_INT_H

#include <vector>
#include <string>
#include <iostream>

namespace euler
{
    template<typename T>
    class BigInt
    {
    public:
        BigInt();
        BigInt(unsigned long long value, unsigned long long max_num_digits = 0);
        BigInt(const std::string& digits, unsigned long long max_num_digits = 0);
        BigInt(const BigInt<T>& big_int);
        BigInt(BigInt<T>&& big_int);

        void operator=(unsigned long long  value);
        void operator=(const BigInt<T>& value);
        void operator=(BigInt<T>&& value);

        void Add(T value);
        void Add(const BigInt<T>& value);
        void operator+=(T value);
        void operator+=(const BigInt<T>& value);
        BigInt<T> operator+(const BigInt<T>& value) const;

        void Subtract(const BigInt<T>& value);
        void operator-=(const BigInt<T>& value);
        BigInt<T> operator-(const BigInt<T>& value) const;

        void Multiply(T value);
        void Multiply(const BigInt<T>&  value);
        void operator*=(T value);
        void operator*=(const BigInt<T>& value);
        BigInt<T> operator*(const BigInt<T>& value);

        bool operator>(const BigInt<T>&  value) const;
        bool operator<(const BigInt<T>&  value) const;
        bool operator<=(const BigInt<T>&  value) const;
        bool operator==(const BigInt<T>& value) const;
        bool operator!=(const BigInt<T>& value) const;

        unsigned int ToUint() const;
        unsigned long long int ToUll() const;
        std::string ToString() const;

        const std::vector<T>& digits() const;
        unsigned long long max_num_digits() const;
        void set_max_num_digits(unsigned long long max_num_digits);
        const typename std::vector<T>::size_type NumDigits() const;

        ~BigInt();
    private:
        std::vector<T> digits_;
        unsigned long long max_num_digits_;
        void ripple_carry();
        bool is_negative_;
    };

    template<typename T>
    BigInt<T>::BigInt() : digits_(1, 0), is_negative_(false), max_num_digits_(0) { }

    template<typename T>
    BigInt<T>::BigInt(unsigned long long value, unsigned long long max_num_digits) :
            is_negative_(false), max_num_digits_(max_num_digits)
    {
        operator=(value);
    }

    template<typename T>
    BigInt<T>::BigInt(const std::string& value, unsigned long long max_num_digits) : max_num_digits_(max_num_digits)
    {
        is_negative_ = value.front() == '-';
        for (auto iter = value.rbegin(); iter != value.rend(); ++iter)
        {
            if (*iter != '-')
                digits_.push_back(*iter - '0');
        }
    }

    template<typename T>
    BigInt<T>::BigInt(const BigInt<T>& big_int) : digits_(big_int.digits_), is_negative_(big_int.is_negative_) { }

    template<typename T>
    BigInt<T>::BigInt(BigInt<T>&& big_int) : digits_(std::move(big_int.digits_)), is_negative_(big_int.is_negative_) { }

    template<typename T>
    void BigInt<T>::operator=(unsigned long long value)
    {
        is_negative_ = false;
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
        is_negative_ = value.is_negative_;
    }

    template<typename T>
    void BigInt<T>::operator=(BigInt<T>&& value)
    {
        digits_ = std::move(value.digits_);
        is_negative_ = value.is_negative_;
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
    void BigInt<T>::operator-=(const BigInt<T>& value)
    {
        Subtract(value);
    }

    template<typename T>
    BigInt<T> BigInt<T>::operator-(const BigInt<T>& value) const
    {
        BigInt<T> temp(*this);
        temp.Subtract(value);
        return temp;
    }

    template<typename T>
    BigInt<T> BigInt<T>::operator+(const BigInt<T>& value) const
    {
        BigInt<T> temp(*this);
        temp.Add(value);
        return temp;
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
    BigInt<T> BigInt<T>::operator*(const BigInt<T>& value)
    {
        BigInt<T> temp(*this);
        temp.Multiply(value);
        return temp;
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
        if (is_negative_)
            value.push_back('-');
        for (auto iter = digits_.rbegin(); iter != digits_.rend(); ++iter)
        {
            value.push_back((char)(*iter + '0'));
        }

        return value;
    }

    template<typename T>
    const std::vector<T>& BigInt<T>::digits() const { return digits_; }

    template<typename T>
    unsigned long long BigInt<T>::max_num_digits() const { return max_num_digits_; }

    template<typename T>
    void BigInt<T>::set_max_num_digits(unsigned long long max_num_digits) { max_num_digits_ = max_num_digits; }

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
            else if (max_num_digits_ == 0 || digits_.size() < max_num_digits_)
                digits_.push_back(value.digits_[i]);
        }

        ripple_carry();
    }

    // TODO: Right now we assume a positive difference
    template<typename T>
    void BigInt<T>::Subtract(const BigInt<T>& value)
    {
        for (unsigned int i = 0; i < value.digits_.size(); ++i)
        {
            if (i < digits_.size())
                digits_[i] -= value.digits_[i];
        }

        ripple_carry();
    }

    template<typename T>
    void BigInt<T>::Multiply(T value)
    {
        if (value == 0 || (digits_.size() == 1 && digits_[0] == 0))
        {
            digits_.clear();
            digits_.push_back(0);
            is_negative_ = false;
            return;
        }
        is_negative_ = value > 0 == is_negative_;
        for (unsigned int i = 0; i < digits_.size(); ++i)
        {
            digits_[i] *= value;
        }

        ripple_carry();
    }

    template<typename T>
    void BigInt<T>::Multiply(const BigInt<T>&  value)
    {
        is_negative_ = !value.is_negative_ == is_negative_;
        BigInt<T> temp(0);
        for (unsigned int i = 0; i < value.NumDigits(); ++i)
        {
            for (unsigned int j = 0; j < NumDigits(); ++j)
            {
                if (i + j < temp.NumDigits())
                    temp.digits_[i + j] += value.digits_[i] * digits_[j];
                else if (max_num_digits_ == 0 || digits_.size() < max_num_digits_)
                    temp.digits_.push_back(value.digits_[i] * digits_[j]);
            }
        }
        temp.ripple_carry();
        digits_ = temp.digits_;
    }

    template<typename T>
    bool BigInt<T>::operator==(const BigInt<T>& value) const
    {
        if (NumDigits() != value.NumDigits() || is_negative_ != value.is_negative_)
            return false;
        for (unsigned int i = 0; i < NumDigits(); ++i)
        {
            if (digits_[i] != value.digits_[i])
                return false;
        }
        return true;
    }

    template<typename T>
    bool BigInt<T>::operator!=(const BigInt<T>& value) const
    {
        return !operator==(value);
    }

    template<typename T>
    bool BigInt<T>::operator>(const BigInt<T>&  value) const
    {
        if (digits_.size() > value.digits_.size() || (!is_negative_ && value.is_negative_))
            return true;
        if (digits_.size() < value.digits_.size() || (is_negative_ && !value.is_negative_))
            return false;
        for (long long i = digits_.size() - 1; i >= 0; --i)
        {
            if (digits_[i] > value.digits_[i])
                return true;
            if (digits_[i] < value.digits_[i])
                return false;
        }
        return false;
    }

    template<typename T>
    bool BigInt<T>::operator<(const BigInt<T>&  value) const
    {
        if (digits_.size() > value.digits_.size() || (!is_negative_ && value.is_negative_))
            return false;
        if (digits_.size() < value.digits_.size() || (is_negative_ && !value.is_negative_))
            return true;
        for (long long i = digits_.size() - 1; i >= 0; --i)
        {
            if (digits_[i] > value.digits_[i])
                return false;
            if (digits_[i] < value.digits_[i])
                return true;
        }
        return false;
    }

    template<typename T>
    bool BigInt<T>::operator<=(const BigInt<T>&  value) const
    {
        return !operator>(value);
    }

    template<typename T>
    void BigInt<T>::ripple_carry()
    {
        for (unsigned int i = 0; i < digits_.size(); ++i)
        {
            if (digits_[i] < 0)
            {
                digits_[i] += 10;
                digits_[i + 1] -= 1;
            }
            else if (digits_[i] >= 10)
            {
                T temp = digits_[i] / 10;
                digits_[i] %= 10;
                unsigned int offset = 1;
                while (temp > 0)
                {
                    if ((i + offset) < digits_.size())
                        digits_[i + offset] += (temp % 10);
                    else if (max_num_digits_ > 0 && digits_.size() >= max_num_digits_)
                        break;
                    else
                        digits_.push_back(temp % 10);
                    ++offset;
                    temp /= 10;
                }
            }
        }
        while (digits_.back() == 0 && digits_.size() > 1)
        {
            digits_.pop_back();
        }
    }

}
#endif //PROJECT_EULER_BIG_INT_H
