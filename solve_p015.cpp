//
// Created by KLam on 8/28/2015.
//

#include "solve_p015.h"
#include <iostream>

using namespace std;

void euler::SolveP015()
{
    const int dim = 21;

    long long lattice[dim][dim];

    for (int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            if (i == 0 || j == 0)
                lattice[i][j] = 1;
            else
                lattice[i][j] = lattice[i - 1][j] + lattice[i][j - 1];
        }
    }

    long long solution = lattice[dim - 1][dim - 1];
    cout << "P015 solution: " << solution << endl;
}