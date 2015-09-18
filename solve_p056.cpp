//
// Created by KLam on 9/18/2015.
//

#include "solve_p056.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

void euler::SolveP056()
{
    const uint max_a = 100;
    const uint max_b = 100;
    uint max_sum = 0;
    vector<uint> multiplier;

    for (uint a = 2; a < max_a; ++a)
    {
        for (uint b = 1; b < max_b; ++b)
        {
            multiplier.clear();
            multiplier.push_back(1);

            for (uint i = 0; i < b; ++i)
            {
                for (uint j = 0; j < multiplier.size(); ++j)
                {
                    multiplier[j] *= a;
                }

                for (uint j = 0; j < multiplier.size(); ++j)
                {
                    if (multiplier[j] >= 10)
                    {
                        uint temp = multiplier[j] / 10;
                        multiplier[j] %= 10;
                        uint offset = 1;
                        while (temp > 0)
                        {
                            if ((j + offset) < multiplier.size())
                                multiplier[j + offset] += (temp % 10);
                            else
                                multiplier.push_back(temp % 10);
                            ++offset;
                            temp /= 10;
                        }
                    }
                }

                uint sum = 0;
                for (uint j = 0; j < multiplier.size(); ++j)
                {
                    sum += multiplier[j];
                }
                if (sum > max_sum)
                    max_sum = sum;
            }
        }
    }

    ull solution = max_sum;
    cout << "P056 solution: " << solution << endl;
}
