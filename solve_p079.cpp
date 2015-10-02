//
// Created by KLam on 9/30/2015.
//

#include "solve_p079.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

namespace euler
{
    const uint log_length = 3;
    void recurse_key_search(const vector<string>& logs, vector<uint> states, string& key, string& best_key, uint depth);
}

void euler::recurse_key_search(const vector<string>& logs, vector<uint> states, string& key, string& best_key, uint depth)
{
    if ( depth >= best_key.size())
        return;
    ++depth;
    bool terminal = true;
    set<char> used_digits;
    for (uint i = 0; i < logs.size(); ++i)
    {
        if (states[i] >= log_length)
            continue;
        terminal = false;
        char digit = logs[i][states[i]];
        if (used_digits.find(digit) != used_digits.end())
            continue;
        used_digits.insert(digit);
        key.push_back(digit);
        for (uint j = 0; j < logs.size(); ++j)
        {
            if (states[j] < log_length && logs[j][states[j]] == digit)
                ++states[j];
        }
        recurse_key_search(logs, states, key, best_key, depth);
        for (uint j = 0; j < logs.size(); ++j)
        {
            if (states[j] > 0 && logs[j][states[j] - 1] == digit)
                --states[j];
        }
        key.pop_back();
    }
    if (terminal && key.length() < best_key.length())
        best_key = key;
}

// Slow and brute-forcey.  Apparently must better ways to do this.
void euler::SolveP079()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p079_keylog.txt");
    string line;
    vector<string> logs;
    while (input.good())
    {
        getline(input, line);
        if (line.size() > 0)
            logs.push_back(line);
    }
    input.close();
    vector<uint>* states = new vector<uint>(logs.size(), 0);
    string key = "";
    string* best_key = new string(logs.size() * log_length + 1, '0');
    recurse_key_search(logs, *states, key, *best_key, 0);

    delete states;
    string solution = *best_key;
    cout << "P079 solution: " << solution << endl;
}