//
// Created by KLam on 10/8/2015.
//

#include "solve_p087.h"
#include <iostream>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;


void euler::SolveP087()
{
    const ull max = 50000000;
    PrimeGenerator<ull> gen(sqrt(max));
    set<ull> matches;

    ull pow4, pow3, pow2;
    for(ull term4 = 2, pow4 = term4 * term4 * term4 * term4; pow4 < max; term4 = gen.NextPrime(term4), pow4 = term4 * term4 * term4 * term4)
    {
        for (ull term3 = 2, pow3 = term3 * term3 * term3; pow4 + pow3 < max; term3 = gen.NextPrime(term3), pow3 = term3 * term3 * term3)
        {
            for (ull term2 = 2, pow2 = term2 * term2; pow4 + pow3 + pow2 < max; term2 = gen.NextPrime(term2), pow2 = term2 * term2)
            {
                matches.insert(pow4 + pow3 + pow2);
            }
        }
    }

    ull solution = matches.size();
    cout << "P087 solution: " << solution << endl;
}