//
// Created by KLam on 8/26/2015.
//

#include "solve_p003.h"
#include <iostream>
#include <vector>
#include "prime_utils.h"

using namespace std;

void euler::SolveP003()
{
    long long target = 600851475143;
    //long long target = 196;
    vector<long long> primes;
    GetNextPrime(primes);

    while (target > 1)
    {
        long long prime = primes.back();
        if (target % prime == 0)
        {
            target /= prime;
            continue;
        }
        GetNextPrime(primes);
    }

    long long solution = primes.back();
    cout << "P003 solution: " << solution << endl;
}