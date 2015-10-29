//
// Created by KLam on 10/29/2015.
//

#ifndef PROJECT_EULER_COMBINATORICS_UTIL_H
#define PROJECT_EULER_COMBINATORICS_UTIL_H

#include <vector>

namespace euler
{
    template<typename T>
    bool next_combination(std::vector<T>& result, T max_value)
    {
        for (long long i = result.size() - 1; i >= 0; --i)
        {
            if (result[i] < max_value - (result.size() - i - 1))
            {
                ++result[i];
                for (long long j = i + 1; j < result.size(); ++j)
                {
                    result[j] = result[j - 1] + 1;
                }
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool next_combination_rep(std::vector<T>& result, T max_value)
    {
        for (long long i = result.size() - 1; i >= 0; --i)
        {
            if (result[i] < max_value)
            {
                ++result[i];
                for (long long j = i + 1; j < result.size(); ++j)
                {
                    result[j] = result[i];
                }
                return true;
            }
        }
        return false;
    }
}



#endif //PROJECT_EULER_COMBINATORICS_UTIL_H
