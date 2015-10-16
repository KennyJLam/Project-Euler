//
// Created by KLam on 10/16/2015.
//

#include "solve_p100.h"
#include <iostream>
#include <algorithm>
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

// This is all trial and error brute forcing and doesn't meet the 1 minute requirements
void euler::SolveP100()
{
    const ull floor = 1000000000000;
    //const ull floor = 32509019101;
    const ull coeff = 707106781186;
    const uint num_coeff_digits = 12;

    long double ceiling = 23661;
    while (ceiling <= floor)
    {
        ceiling *= sqrt(33.97056);
    }

    BigInt<ll> num_discs, num_blue;
    //ull ulldiscs = floor;
    ull ulldiscs = (ull)ceiling;

    for (num_discs = ceiling;;--num_discs,--ulldiscs)
    {
        if (ulldiscs % 100000 == 0)
            cout << ulldiscs << endl;
        num_blue = num_discs;
        num_blue *= coeff;
        num_blue.TruncateDigits(num_coeff_digits);
        ++num_blue;

        BigInt<ll> discs_poly = num_discs * num_discs;
        discs_poly -= num_discs;
        bool found_match = false;
        for (;;++num_blue)
        {
            BigInt<ll> blue_poly = num_blue * num_blue;
            blue_poly -= num_blue;
            blue_poly *= 2;

            if (blue_poly > discs_poly)
                break;
            else if (discs_poly == blue_poly)
            {
                found_match = true;
                break;
            }
        }
        if (found_match)
            break;
    }

    cout << num_blue.ToUll() << "/" << num_discs.ToUll() << endl;
    ull solution = num_blue.ToUll();
    cout << "P100 solution: " << solution << endl;
}
