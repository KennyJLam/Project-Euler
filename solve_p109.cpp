//
// Created by KLam on 10/26/2015.
//

#include "solve_p109.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP109()
{
    const ull max = 100;

    set<ull> singles, doubles, triples;
    for (ull n = 1; n <= 20; ++n)
    {
        singles.insert(n);
        doubles.insert(2 * n);
        triples.insert(3 * n);
    }
    singles.insert(25);
    doubles.insert(50);

    vector<ull> all_points;
    copy(singles.begin(), singles.end(), back_inserter(all_points));
    copy(doubles.begin(), doubles.end(), back_inserter(all_points));
    copy(triples.begin(), triples.end(), back_inserter(all_points));

    ull total_count = 0;
    for (ull n = 1; n < max; ++n)
    {
        ull count = 0;
        if ((n <= 40 && n % 2 == 0) || n == 50)
            ++count;

        for (ull d : doubles)
        {
            ull remainder = n - d;
            for (ull i = 0; i < all_points.size(); ++i)
            {
                if (all_points[i] == remainder)
                    ++count;
                for (ull j = i; j < all_points.size(); ++j)
                {
                    ull sum = all_points[i] + all_points[j];
                    if (sum == remainder)
                        ++count;
                }
            }
        }
        total_count += count;
    }

    ull solution = total_count;
    cout << "P109 solution: " << solution << endl;
}
