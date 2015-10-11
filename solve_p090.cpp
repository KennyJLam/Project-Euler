//
// Created by Klam on 10/10/2015.
//

#include "solve_p090.h"
#include <iostream>
#include <vector>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    bool next_combination(vector<uint>& dice);
    bool has_all_squares(const vector<uint>& dice1, const vector<uint>& dice2);
}

bool euler::next_combination(vector<uint> &dice)
{
    for (ll i = 0; i < dice.size(); ++i)
    {
        ll n = dice.size() - i - 1;
        if (dice[n] < 9 - i)
        {
            ++dice[n];
            for (ll j = n + 1; j < dice.size(); ++j)
            {
                dice[j] = dice[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

bool euler::has_all_squares(const vector<uint>& dice1, const vector<uint>& dice2)
{
    set<uint> set1, set2;
    for (uint side : dice1)
    {
        set1.insert(side);
    }
    for (uint side : dice2)
    {
        set2.insert(side);
    }
    if ((set1.find(0) == set1.end() || set2.find(1) == set2.end())
        && (set2.find(0) == set2.end() || set1.find(1) == set1.end()))
        return false;
    if ((set1.find(0) == set1.end() || set2.find(4) == set2.end())
        && (set2.find(0) == set2.end() || set1.find(4) == set1.end()))
        return false;
    if ((set1.find(0) == set1.end() || (set2.find(6) == set2.end() && set2.find(9) == set2.end()))
        && (set2.find(0) == set2.end() || (set1.find(6) == set1.end() && set1.find(9) == set1.end())))
        return false;
    if ((set1.find(1) == set1.end() || (set2.find(6) == set2.end() && set2.find(9) == set2.end()))
        && (set2.find(1) == set2.end() || (set1.find(6) == set1.end() && set1.find(9) == set1.end())))
        return false;
    if ((set1.find(2) == set1.end() || set2.find(5) == set2.end())
        && (set2.find(2) == set2.end() || set1.find(5) == set1.end()))
        return false;
    if ((set1.find(3) == set1.end() || (set2.find(6) == set2.end() && set2.find(9) == set2.end()))
        && (set2.find(3) == set2.end() || (set1.find(6) == set1.end() && set1.find(9) == set1.end())))
        return false;
    if ((set1.find(4) == set1.end() || (set2.find(6) == set2.end() && set2.find(9) == set2.end()))
        && (set2.find(4) == set2.end() || (set1.find(6) == set1.end() && set1.find(9) == set1.end())))
        return false;
    if ((set1.find(8) == set1.end() || set2.find(1) == set2.end())
        && (set2.find(8) == set2.end() || set1.find(1) == set1.end()))
        return false;
    return true;
}

void euler::SolveP090()
{
    vector<uint> dice1 { 0, 1, 2, 3, 4, 5 };
    vector<uint> dice2;

    uint count = 0;

    do
    {
        dice2 = dice1;
        do
        {
            if (has_all_squares(dice1, dice2))
                ++count;
        }
        while (next_combination(dice2));
    }
    while (next_combination(dice1));

    ull solution = count;
    cout << "P090 solution: " << solution << endl;
}