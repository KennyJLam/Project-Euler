//
// Created by KLam on 10/23/2015.
//

#include "solve_p106.h"
#include <iostream>
#include <algorithm>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    ull needed_sums(const vector<ull>& target_set);
}

ull euler::needed_sums(const vector<ull>& target_set)
{
    const ull max_n = target_set.size() / 2;
    set<ull> sums;
    ull count = 0;

    vector<vector<ull>::const_iterator> iters;
    for (ull n = 1; n <= max_n; ++n)
    {
        iters.clear();
        for (ull i = 0; i < n; ++i)
        {
            iters.push_back(target_set.begin() + i);
        }
        vector<vector<ull>> subsets;
        for (;;)
        {
            vector<ull> subset(n, 0ull);
            transform(iters.begin(), iters.end(), subset.begin(), [] (vector<ull>::const_iterator iter) { return *iter; });
            subsets.push_back(move(subset));

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
        set<ull> index;
        for (ull i = 0; i < subsets.size() - 1; ++i)
        {
            for (ull j = i + 1;j < subsets.size(); ++j)
            {
                const auto& a = subsets[i];
                const auto& b = subsets[j];
                index.clear();
                for_each(a.begin(), a.end(), [&](ull val) { index.insert(val); });
                bool has_equals = false, has_greater = false, has_less = false;
                for (ull k = 0; k < n; ++k)
                {
                    if (index.find(b[k]) != index.end())
                    {
                        has_equals = true;
                        break;
                    }
                    else if (a[k] > b[k])
                        has_greater = true;
                    else if (a[k] < b[k])
                        has_less = true;
                }
                if (!has_equals && (has_greater && has_less))
                    ++count;
            }
        }
    }
    return count;
}

void euler::SolveP106()
{
    const ull max_n = 12;
    vector<ull> target_set { 1 };
    for (ull n = 2; n <= max_n; ++n)
    {
        ull mid = target_set[target_set.size() / 2];
        transform(target_set.begin(), target_set.end(), target_set.begin(), [&] (ull val) { return val + mid; });
        target_set.insert(target_set.begin(), mid);
    }

    ull solution = needed_sums(target_set);
    cout << "P107 solution: " << solution << endl;
}