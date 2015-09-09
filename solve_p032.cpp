//
// Created by KLam on 9/9/2015.
//

#include "solve_p032.h"
#include <iostream>
#include <unordered_set>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP032()
{
    unordered_set<int> digits;
    unordered_set<int> products;

    for (int a = 123; a < 9999; ++a)
    {
        for (int b = 2; b < a; ++b)
        {
            int product = a * b;
            if (product >= 9999)
                continue;
            digits.clear();
            int scratch_a = a;
            while (scratch_a > 0)
            {
                int scratch = scratch_a % 10;
                if (scratch != 0)
                    digits.insert(scratch);
                scratch_a /= 10;
            }
            int scratch_b = b;
            while (scratch_b > 0)
            {
                int scratch = scratch_b % 10;
                if (scratch != 0)
                    digits.insert(scratch);
                scratch_b /= 10;
            }
            int scratch_c = product;
            while (scratch_c > 0)
            {
                int scratch = scratch_c % 10;
                if (scratch != 0)
                    digits.insert(scratch);
                scratch_c /= 10;
            }
            if (digits.size() == 9)
                products.insert(product);
        }
    }

    ull sum = 0;
    for (int product : products)
    {
        sum += product;
    }
    ull solution = sum;
    cout << "P032 solution: " << solution << endl;
}
