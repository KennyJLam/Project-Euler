//
// Created by KLam on 9/14/2015.
//

#include "solve_p047.h"
#include <iostream>
#include "generators/prime_generator.h"


typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

// A bit slow
void euler::SolveP047()
{
    PrimeGenerator<ull> gen;
    const int match_target = 4;

    ull prev3 = 0, prev2 = 0, prev = 0;
    uint num_matches = 0;

    for(ull n = 210;;++n)
    {
        set<ull> prime_factors;
        gen.PrimeFactors(n, prime_factors);
        if (prime_factors.size() == match_target)
        {
            ++num_matches;
            if (num_matches == 4)
                break;
            prev3 = prev2;
            prev2 = prev;
            prev = n;
        }
        else
        {
            prev3 = prev2 = prev = num_matches = 0;
        }
    }

    ull solution = prev3;
    cout << "P047 solution: " << solution << endl;
}