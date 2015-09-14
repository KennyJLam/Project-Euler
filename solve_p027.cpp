//
// Created by KLam on 9/1/2015.
//

#include "solve_p027.h"
#include "generators/prime_generator.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP027()
{
    const int max = 1000;
    int max_n = 0;
    int best_a = 0, best_b = 0;

    PrimeGenerator<int> gen(150);

    int b = gen.NextPrime();
    while (b < max)
    {
        int a = -max + 1;
        a = a <= -b ? -b : a;
        if (a % 2 == 0 && b %2 == 1)
            ++a;
        while (a < max)
        {
            int n;
            for (n = 0;; ++n)
            {
                int val = n * n + a * n + b;
                if (!gen.IsPrime(val))
                    break;
            }
            if (n > max_n)
            {
                max_n = n;
                best_a = a;
                best_b = b;
            }

            if (b % 2 == 0)
                ++a;
            else
                a += 2;
        }

        b = gen.NextPrime();
    }

    int solution = best_a * best_b;
    cout << "P027 solution: " << solution << endl;
}
