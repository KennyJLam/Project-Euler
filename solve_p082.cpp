//
// Created by KLam on 10/6/2015.
//

#include "solve_p082.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP082()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p082_matrix.txt");
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
    for (ull col = 0; col < dim; ++col)
    {
        for (ull row = 0; row < dim; ++row)
        {
            if (col == 0)
                path_lengths[row][col] = matrix[row][col];
            else
            {
                ull current_best = path_lengths[row][col - 1];
                if (row < dim - 1 && path_lengths[row][col - 1] > matrix[row + 1][col])
                {
                    ull sum = 0;
                    for (ull i_row = row + 1; i_row < dim; ++i_row)
                    {
                        sum += matrix[i_row][col];
                        current_best = min(current_best, sum + path_lengths[i_row][col - 1]);
                    }

                }
                if (row > 0 && path_lengths[row][col - 1] > matrix[row - 1][col])
                {
                    ull sum = 0;
                    for (ll i_row = row - 1; i_row > 0; --i_row)
                    {
                        sum += matrix[i_row][col];
                        current_best = min(current_best, sum + path_lengths[i_row][col - 1]);
                    }
                }
                path_lengths[row][col] = current_best + matrix[row][col];
            }
        }
    }

    ull best_path_length = path_lengths.back().back();
    for (const vector<ull>& row : path_lengths)
    {
        best_path_length = min(best_path_length, row.back());
    }
    ull solution = best_path_length;
    cout << "P082 solution: " << solution << endl;
}
