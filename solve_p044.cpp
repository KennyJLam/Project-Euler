//
// Created by KLam on 9/14/2015.
//

#include "solve_p044.h"
#include <iostream>
#include "generators/pentagonal_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

// This works by luck, the forum has a number of proper solutions
void euler::SolveP044()
{
    PentagonalGenerator<ull> gen;
    uint n_stop = 0, m_stop = 0;
    ull pent_n_stop = 0, pent_m_stop = 0;

    uint n;
    for (n = 1;;++n)
    {
        bool stop = false;
        ull current = gen.Next();
        for (uint m = n - 1;m >= 1; --m)
        {
            ull pent_m = m * (3 * m - 1) / 2;
            if (gen.IsPentagonal(current - pent_m) && gen.IsPentagonal(current + pent_m))
            {
                n_stop = n;
                m_stop = m;
                pent_n_stop = current;
                pent_m_stop = pent_m;
                stop = true;
            }
        }
        if (stop)
            break;
    }

    ull solution = pent_n_stop - pent_m_stop;
    cout << "P044 solution: " << solution << endl;
}
