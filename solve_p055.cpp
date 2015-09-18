//
// Created by KLam on 9/18/2015.
//

#include "solve_p055.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

void euler::SolveP055()
{
    const uint max = 10000;
    const uint max_iter = 50;
    uint num_matches = 0;
    vector<char> adder;

    for (uint n = 10; n < max; ++n)
    {
        adder.clear();
        uint temp = n;
        while(temp > 0)
        {
            adder.push_back((char)(temp % 10));
            temp /= 10;
        }

        bool match = true;
        for (uint i = 0; i < max_iter; ++i)
        {
            if (adder.size() % 2 == 1)
                adder[adder.size() / 2] *= 2;
            for (uint j = 0; j < adder.size() / 2; ++j)
            {
                char sum = adder[j] + adder[adder.size() - j - 1];
                adder[j] = adder[adder.size() - j - 1] = sum;
            }

            for (uint j = 0; j < adder.size(); ++j)
            {
                if (adder[j] >= 10)
                {
                    adder[j] %= 10;
                    if (j == adder.size() - 1)
                        adder.push_back(1);
                    else
                        ++adder[j + 1];
                }
            }

            bool is_palindrome = true;
            for (uint j = 0; j < adder.size() / 2; ++j)
            {
                if (adder[j] != adder[adder.size() - j - 1])
                {
                    is_palindrome = false;
                    break;
                }
            }

            if (is_palindrome)
            {
                match = false;
                break;
            }
        }
        if (match)
            ++num_matches;
    }

    ull solution = num_matches;
    cout << "P055 solution: " << solution << endl;
}
