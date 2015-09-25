//
// Created by KLam on 9/25/2015.
//

#include "solve_p067.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP067()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p067_triangle.txt");
    string line;
    vector<vector<uint>*> pyramid;
    while (input.good())
    {
        getline(input, line);
        vector<uint>* layer = new vector<uint>();
        stringstream ss(line);
        string value;
        while (getline(ss, value, ' '))
        {
            uint sum = 0;
            for (char c : value)
            {
                sum = sum * 10 + c - '0';
            }
            layer->push_back(sum);
        }
        if (layer->size() > 0)
            pyramid.push_back(layer);
    }
    input.close();

    ull layer[pyramid.size()];
    for (int i = 0; i < pyramid.size(); ++i)
    {
        layer[i] = 0;
    }
    for (int i = pyramid.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            layer[j] += (ull)(*pyramid[i])[j];
        }
        for (int j = 0; j < i; ++j)
        {
            layer[j] = layer[j] > layer[j + 1] ? layer[j] : layer[j + 1];
        }
    }

    for (auto v : pyramid)
    {
        delete v;
    }

    ull solution = layer[0];
    cout << "P067 solution: " << solution << endl;
}