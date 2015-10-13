//
// Created by KLam on 10/13/2015.
//

#include "solve_p097.h"
#include <iostream>
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP097()
{
    const ull exp = 7830457;
    BigInt<ull> prime(1, 15);

    for (uint i = 0; i < exp; ++i)
    {
        prime *= 2;
    }

    prime *= 28433;
    prime += 1;

    ull result = 0;
    for (int i = 9; i >= 0; --i)
    {
        result = 10 * result + prime.digits()[i];
    }
    ull solution = result;
    cout << "P097 solution: " << solution << endl;
}
