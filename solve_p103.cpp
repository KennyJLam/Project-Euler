//
// Created by KLam on 10/21/2015.
//

#include "solve_p103.h"
#include <iostream>
#include <algorithm>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    bool next_candidate(vector<ull>&target_set);
    bool check_sums(const vector<ull>&target_set);
}

bool euler::next_candidate(vector<ull>& target_set)
{
    const ull max_n = target_set.size();
    for (;;)
    {
        bool found_candidate = false;
        ull front = target_set[0] + target_set[1];
        for (ll n = max_n - 1; n > 0; --n)
        {
            ull ceiling =  n == 1 ? target_set[0] * 2 : front - 1;
            if (target_set[n] < ceiling - 1)
            {
                ++target_set[n];
                for (ll j = n + 1; j < max_n; ++j)
                {
                    target_set[j] = target_set[j - 1] + 1;
                }
                found_candidate = true;
                break;
            }
        }
        if (!found_candidate)
            return false;

        ull running_sum = target_set.front();
        ull running_back_sum = 0;
        for (ull n = 0; n < (max_n - 1) / 2; ++n)
        {
            running_sum += target_set[n + 1];
            running_back_sum += target_set[max_n - n - 1];
            if (running_sum <= running_back_sum)
            {
                found_candidate = false;
                break;
            }
        }
        if (found_candidate)
            return true;
    }
}

bool euler::check_sums(const vector<ull>& target_set)
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


            for (ll j = iters.size() - 1; j >= 0; --j)
            {
                if (iters[j] != target_set.end() - (iters.size() - j - 1))
                {
                    ++iters[j];
                    for (ll k = j + 1; k < iters.size(); ++k)
                    {
                        iters[k] = iters[k - 1] + 1;
                    }
                    break;
                }
            }
            bool end = true;
            for (ll j = 0; j < iters.size(); ++j)
            {
                if (iters[j] != target_set.end() - (iters.size() - j - 1))
                {
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

// Sloppy, and tons of arbitrary assumptions.  No clue how to generalize this.
void euler::SolveP103()
{
    //vector<ull> target_set { 6, 7, 8, 9, 10 };
    //vector<ull> target_set { 11, 17, 18, 19, 20, 21 };
    vector<ull> target_set { 20, 31, 32, 33, 34, 35, 36 };

    ull best_sum = 9999999999;
    vector<ull> best_set;

    while (next_candidate(target_set))
    {
        if (check_sums(target_set))
        {
            ull sum = accumulate(target_set.begin(), target_set.end(), 0ull);
            if (sum < best_sum)
            {
                best_set = target_set;
                best_sum = sum;
            }
        }
    }

    string key = "";
    for (ull number : best_set)
    {
        key.append(to_string(number));
    }
    string solution = key;
    cout << "P103 solution: " << solution << endl;
}
