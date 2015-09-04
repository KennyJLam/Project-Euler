//
// Created by KLam on 8/28/2015.
//

#ifndef PROJECT_EULER_SOLVE_P014_H
#define PROJECT_EULER_SOLVE_P014_H

#include <map>

namespace euler
{
    int GetCollatzLength(long long seed, std::map<long long,int>& table);
    void SolveP014();
}

#endif //PROJECT_EULER_SOLVE_P014_H
