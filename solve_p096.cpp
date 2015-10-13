//
// Created by KLam on 10/13/2015.
//

#include "solve_p096.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    bool recurse_sudoku(vector<vector<uint>>& grid);
}

bool euler::recurse_sudoku(vector<vector<uint>>& grid)
{
    for (uint row = 0; row < 9; ++row)
    {
        for (uint col = 0; col < 9; ++col)
        {
            if (grid[row][col] != 0)
                continue;
            set<uint> possibles { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            for (uint i = 0; i < 9; ++i)
            {
                if (possibles.find(grid[row][i]) != possibles.end())
                    possibles.erase(grid[row][i]);
                if (possibles.find(grid[i][col]) != possibles.end())
                    possibles.erase(grid[i][col]);
                uint box_row = row / 3 * 3 + i / 3;
                uint box_col = col / 3 * 3 + i % 3;
                if (possibles.find(grid[box_row][box_col]) != possibles.end())
                    possibles.erase(grid[box_row][box_col]);
            }
            for (uint possible : possibles)
            {
                grid[row][col] = possible;
                if (recurse_sudoku(grid))
                    return true;
                grid[row][col] = 0;
            }
            return false;
        }
    }
    return true;
}

void euler::SolveP096()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p096_sudoku.txt");
    string line;
    vector<vector<vector<uint>>> grids;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        if (line[0] == 'G')
            grids.push_back(vector<vector<uint>>());
        else
        {
            grids.back().push_back(vector<uint>());
            for (char c : line)
            {
                grids.back().back().push_back((uint)(c - '0'));
            }
        }
    }
    input.close();

    vector<uint> keys;
    for (auto& grid : grids)
    {
        recurse_sudoku(grid);
        keys.push_back(100 * grid[0][0] + 10 * grid[0][1] + grid[0][2]);
    }

    ull solution = accumulate(keys.begin(), keys.end(), 0ull);
    cout << "P096 solution: " << solution << endl;
}
