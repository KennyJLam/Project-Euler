//
// Created by KLam on 8/26/2015.
//

#include "solve_p010.h"
#include "prime_utils.h"
#include <iostream>

using namespace std;

void euler::SolveP010()
{
    const int target = 2000000;
    vector<long long> primes;
    long long sum = 0;
    for (;;)
    {
        GetNextPrime(primes);
        //cout << primes.back() << endl;
        if (primes.back() >= target)
            break;
        sum += primes.back();
    }

    long long solution = sum;
    cout << "P010 solution: " << solution << endl;
}