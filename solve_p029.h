//
// Created by KLam on 9/8/2015.
//

#ifndef PROJECT_EULER_SOLVE_P029_H
#define PROJECT_EULER_SOLVE_P029_H

namespace euler
{
    void SolveP029();

    template<typename T>
    struct APtrComp
    {
        bool operator()(const T* lhs, const T* rhs) const;
    };

    template<typename T>
    bool APtrComp<T>::operator()(const T* lhs, const T* rhs) const
    {
        return *lhs < *rhs;
    }
}

#endif //PROJECT_EULER_SOLVE_P029_H
