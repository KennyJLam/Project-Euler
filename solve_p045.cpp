//
// Created by KLam on 9/14/2015.
//

#include "solve_p045.h"
#include <iostream>
#include "generators/triangle_num_generator.h"
#include "generators/pentagonal_generator.h"
#include "generators/hexagonal_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP045()
{
    const ull min = 40755;
    TriangleNumGenerator<ull> gen_t(min);
    PentagonalGenerator<ull> gen_p(min);
    HexagonalGenerator<ull> gen_h(min);
    gen_h.Next(min);

    ull match;
    for(;;)
    {
        ull target = gen_h.Next();
        if (gen_t.IsTriangular(target) && gen_p.IsPentagonal(target))
        {
            match = target;
            break;
        }
    }

    ull solution = match;
    cout << "P045 solution: " << solution << endl;
}