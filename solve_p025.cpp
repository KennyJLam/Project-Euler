//
// Created by KLam on 9/1/2015.
//

#include "solve_p025.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP025()
{
    const int target_digits = 1000;
    vector<int> x(1, 1);
    vector<int> y(1, 1);
    vector<int>* current = &x;
    vector<int>* prev = &y;

    uint i;
    for(i = 3;;++i)
    {
        for (size_t j = 0; j < current->size(); ++j)
        {
            if (j >= prev->size())
                prev->push_back(0);
            (*prev)[j] += (*current)[j];
            if ((*prev)[j] >= 10)
            {
                (*prev)[j] %= 10;
                if (j + 1 >= prev->size())
                    prev->push_back(0);
                ++(*prev)[j + 1];
            }
        }

        vector<int>* temp = current;
        current = prev;
        prev = temp;

        if (current->size() >= target_digits)
            break;
    }

    uint solution = i;
    cout << "P025 solution: " << solution << endl;
}
