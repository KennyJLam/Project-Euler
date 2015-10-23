//
// Created by KLam on 10/22/2015.
//

#include "solve_p105.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    bool check_sums_105(const vector<ull>& target_set);
}

bool euler::check_sums_105(const vector<ull>& target_set)
{
    const ull max_n = target_set.size() / 2;
    set<ull> sums;

    vector<vector<ull>::const_iterator> iters;
    for (ull n = 1; n <= max_n; ++n)
    {
        iters.clear();
        for (ull i = 0; i < n; ++i)
        {
            iters.push_back(target_set.begin() + i);
        }

        for (;;)
        {
            ull sum = accumulate(iters.begin(), iters.end(), 0ull, [] (ull running, vector<ull>::const_iterator i) { return running + *i; });
            if (sums.find(sum) != sums.end())
                return false;

            sums.insert(sum);

            bool end = true;
            for (ll j = iters.size() - 1; j >= 0; --j)
            {
                if (iters[j] != target_set.end() - (iters.size() - j))
                {
                    ++iters[j];
                    for (ll k = j + 1; k < iters.size(); ++k)
                    {
                        iters[k] = iters[k - 1] + 1;
                    }
                    end = false;
                    break;
                }
            }
            if (end)
                break;
        }
    }
    return true;
}

void euler::SolveP105()
{
    vector<vector<ull>> target_sets;
    ifstream input("C:/Dev/Project-Euler/inputs/p105_sets.txt");
    string line;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        target_sets.push_back(vector<ull>());
        stringstream ss(line);
        string value;
        while (ss.good())
        {
            getline(ss, value, ',');
            target_sets.back().push_back(stoull(value));
        }
        sort(target_sets.back().begin(), target_sets.back().end());
    }
    input.close();

    ull sum = 0;
    for (const auto& target_set : target_sets)
    {
        ull max_n = target_set.size();
        ull running_sum = target_set.front();
        ull running_back_sum = 0;
        bool valid = true;
        for (ull n = 0; n < (max_n - 1) / 2; ++n)
        {
            running_sum += target_set[n + 1];
            running_back_sum += target_set[max_n - n - 1];
            if (running_sum <= running_back_sum)
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;

        if (check_sums_105(target_set))
            sum += accumulate(target_set.begin(), target_set.end(), 0ull);
    }

    ull solution = sum;
    cout << "P105 solution: " << solution << endl;
}