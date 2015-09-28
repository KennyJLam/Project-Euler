//
// Created by KLam on 9/28/2015.
//

#include "solve_p072.h"
#include <iostream>
#include <map>
#include "generators/prime_generator.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP072()
{
    const uint max = 1000000;
    PrimeGenerator<ull> gen(sqrt(max) + 1);

    ull sum = 0;
    for (ull n = 2; n <= max; ++n)
    {
        ull totient = 0;
        if (gen.IsPrime(n))
            totient = n - 1;
        else
        {
            set<ull> prime_factors;
            gen.PrimeFactors(n, prime_factors);
            totient = n;
            for (ull prime_factor : prime_factors)
            {
                totient /= prime_factor;
                totient *= (prime_factor - 1);
            }
        }
        sum += totient;
    }

    ull solution = sum;
    cout << "P072 solution: " << solution << endl;
}
