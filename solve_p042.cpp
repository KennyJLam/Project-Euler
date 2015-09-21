//
// Created by KLam on 9/10/2015.
//

#include "solve_p042.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

void euler::SolveP042()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p042_words.txt");
    string value;
    vector<string> words;
    uint max_len = 0;
    while (input.good())
    {
        getline(input, value, ',');
        words.push_back(value.substr(1, value.size() - 2));
        if (words.back().length() > max_len)
            max_len = words.back().length();
    }
    input.close();

    int n = 1;
    unordered_set<int> triangle_numbers;
    int triangle_num = 1;
    while (triangle_num < max_len * 26)
    {
        triangle_num = n * (n + 1) / 2;
        triangle_numbers.insert(triangle_num);
        ++n;
    }

    int num_matches = 0;
    for (string word : words)
    {
        int score = 0;
        for (char c : word)
        {
            score += c - 'A' + 1;
        }
        if (triangle_numbers.find(score) != triangle_numbers.end())
            ++num_matches;
    }


    int solution = num_matches;
    cout << "P042 solution: " << solution << endl;
}