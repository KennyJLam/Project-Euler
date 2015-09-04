//
// Created by KLam on 8/26/2015.
//

#include "solve_p007.h"
#include <iostream>
#include <vector>
#include "prime_utils.h"

using namespace std;

void euler::SolveP007()
{
    const int target = 10001;
    vector<long long> primes;
    for (int i = 0; i < target; ++i)
    {
        GetNextPrime(primes);
    }

    long long solution = primes.back();
    cout << "P007 solution: " << solution << endl;
}
