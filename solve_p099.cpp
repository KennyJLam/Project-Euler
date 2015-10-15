//
// Created by KLam on 10/15/2015.
//

#include "solve_p099.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP099()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p099_base_exp.txt");
    string line;
    vector<pair<ull,ull>> base_exp_pairs;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        stringstream ss(line);
        string value;
        getline(ss, value, ',');
        ull base = stoull(value);
        getline(ss, value, ',');
        ull exp = stoull(value);
        base_exp_pairs.push_back(pair<ull,ull>(base, exp));
    }
    input.close();

    ull max_line = 0;
    double max_log = 0;
    for (ull i = 0; i < base_exp_pairs.size(); ++i)
    {
        ull base = base_exp_pairs[i].first;
        ull exp = base_exp_pairs[i].second;
        double log_value = exp * log(base);
        if (log_value > max_log)
        {
            max_log = log_value;
            max_line = i + 1;
        }
    }

    ull solution = max_line;
    cout << "P099 solution: " << solution << endl;
}
