//
// Created by KLam on 9/10/2015.
//

#include "solve_p039.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP039()
{
    int p_max = 1000;
    int best_num_triplets = 0;
    int best_p = 0;

    for (int p = 6; p <= p_max; ++p)
    {
        int num_triplets = 0;
        for (int a = 3; a < (p - 3) / 3; ++a)
        {
            for (int b = a + 1; b < (p - a) / 2; ++b)
            {
                int c = p - a - b;
                if (a * a + b * b == c * c)
                    ++num_triplets;
            }
        }
        if (num_triplets > best_num_triplets)
        {
            best_num_triplets = num_triplets;
            best_p = p;
        }
    }

    int solution = best_p;
    cout << "P039 solution: " << solution << endl;
}