//
// Created by KLam on 8/31/2015.
//

#include "solve_p022.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;


void euler::SolveP022()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p022_names.txt");
    string value;
    vector<string> names;
    while (input.good())
    {
        getline(input, value, ',');
        names.push_back(value.substr(1, value.size() - 2));
    }
    input.close();
    sort(names.begin(), names.end());

    ull score_sum = 0;
    for (int i = 0; i < names.size(); ++i)
    {
        unsigned int sum = 0;
        for (int j = 0; j < names[i].length(); ++j)
        {
            sum += names[i][j] - 'A' + 1;
        }
        score_sum += (i + 1) * sum;
    }

    ull solution = score_sum;
    cout << "P022 solution: " << solution << endl;
}