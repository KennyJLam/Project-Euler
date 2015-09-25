//
// Created by KLam on 9/25/2015.
//

#ifndef PROJECT_EULER_CONTINUED_FRACTIONS_UTIL_H
#define PROJECT_EULER_CONTINUED_FRACTIONS_UTIL_H

#include <vector>
#include <set>
#include <cmath>
#include <tuple>
#include <sstream>
#include "math_utils.h"

namespace euler
{
    //Gets the continued fraction terms of the square root of value
    template<typename T, typename U>
    void get_sqrt_terms(T value, T& term0, std::vector<U>& terms)
    {
        terms.clear();
        if (is_perfect_square(value))
            return;
        std::set<std::tuple<T, T>> fracs;

        std::tuple<T,T> frac;
        T denom = 1;
        T term = (T)(std::sqrt(value));
        term0 = term;
        T subtrahend = term0;
        fracs.insert(std::make_tuple(subtrahend, denom));
        for(;;)
        {
            denom = (value - subtrahend * subtrahend) / denom;
            term = (T)((std::sqrt(value) + subtrahend) / denom);
            subtrahend = term * denom - subtrahend;

            terms.push_back(term);
            frac = std::make_tuple(subtrahend, denom);
            if (fracs.find(frac) != fracs.end())
                break;

            fracs.insert(frac);
        }
    }

    template<typename T>
    std::string terms_str(T term0, const std::vector<T>& terms)
    {
        std::stringstream ss;
        ss << "[" << term0 << ";(";
        for (unsigned int i = 0; i < terms.size(); ++i)
        {
            ss << terms[i];
            if (i != terms.size() - 1)
                ss << ',';
        }
        ss << ")]" << std::endl;
        return ss.str();
    }
}



#endif //PROJECT_EULER_CONTINUED_FRACTIONS_UTIL_H
