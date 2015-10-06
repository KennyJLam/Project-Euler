//
// Created by KLam on 10/6/2015.
//

#include "solve_p081.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

void euler::SolveP081()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p081_matrix.txt");
    string line;
    vector<vector<uint>> matrix;
    vector<vector<ull>> path_lengths;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        stringstream ss(line);
        string value;
        matrix.push_back(vector<uint>());
        path_lengths.push_back(vector<ull>());
        while (getline(ss, value, ','))
        {
            matrix.back().push_back(stoul(value));
            path_lengths.back().push_back(0);
        }
    }
    input.close();

    ull dim = matrix.size();
    path_lengths.front().front() = matrix.front().front();
    for (ull row = 0; row < dim; ++row)
    {
        for (ull col = 0; col < dim; ++col)
        {
            if (row == 0 && col == 0)
                continue;
            if (row == 0)
                path_lengths[row][col] = path_lengths[row][col - 1] + matrix[row][col];
            else if (col == 0)
                path_lengths[row][col] = path_lengths[row - 1][col] + matrix[row][col];
            else
                path_lengths[row][col] = min(path_lengths[row - 1][col], path_lengths[row][col - 1]) + matrix[row][col];
        }
    }

    ull solution = path_lengths.back().back();
    cout << "P081 solution: " << solution << endl;
}