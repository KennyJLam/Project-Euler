//
// Created by KLam on 9/25/2015.
//

#include "solve_p068.h"
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP068()
{
    vector<uint> ring = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    set<string> solutions;

    do
    {
        if (((ring[5] + ring[0] + ring[1]) == (ring[6] + ring[1] + ring[2])) &&
            ((ring[6] + ring[1] + ring[2]) == (ring[7] + ring[2] + ring[3])) &&
            ((ring[7] + ring[2] + ring[3]) == (ring[8] + ring[3] + ring[4])) &&
            ((ring[8] + ring[3] + ring[4]) == (10 + ring[4] + ring[0])))
        {
            uint min_index = 0, min_value = 10;
            for (uint i = 5; i <= 8; ++i)
            {
                if (ring[i] < min_value)
                {
                    min_index = i;
                    min_value = ring[i];
                }
            }
            stringstream ss;
            uint index_head = min_index;
            for (uint i = 0; i < 5; ++i)
            {
                if (index_head != 9)
                {
                    ss << ring[index_head] << ring[index_head - 5] << ring[index_head - 4];
                    ++index_head;
                }
                else
                {
                    ss << 10 << ring[4] << ring[0];
                    index_head = 5;
                }
            }
            solutions.insert(ss.str());
        }
    }
    while (next_permutation(ring.begin(), ring.end()));

    string solution = *solutions.rbegin();
    cout << "P068 solution: " << solution << endl;
}