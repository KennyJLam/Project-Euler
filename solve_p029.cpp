//
// Created by KLam on 9/8/2015.
//

#include "solve_p029.h"
#include "prime_generator.h"
#include "prime_utils.h"
#include <iostream>
#include <memory>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

// This is really nasty.  Should probably look for a better way to do this.
void euler::SolveP029()
{
    set<vector<int>*, APtrComp<vector<int>>> factors;
    const int max_a = 100;
    const int max_b = 100;
    const int min_a = 2;
    const int min_b = 2;
    PrimeGenerator<int> gen(100);

    for (int a = min_a; a <= max_a; ++a)
    {
        map<int,int> factor_map;
        GetPrimeFactorCounts(a, factor_map);
        for (int b = min_b; b <= max_b; ++b)
        {
            vector<int>* factor_vec = new vector<int>();
            for (int prime : gen.primes())
            {
                if (prime > max_a)
                    break;
                if (a == prime || factor_map.find(prime) != factor_map.end())
                    factor_vec->push_back(b * factor_map[prime]);
                else
                    factor_vec->push_back(0);
            }
            //vector<int> blah = *factor_vec;
            factors.insert(factor_vec);
        }
    }


    int solution = factors.size();
    for (auto v : factors)
    {
        delete v;
    }
    cout << "P029 solution: " << solution << endl;
}
