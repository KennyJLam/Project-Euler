//
// Created by KLam on 10/6/2015.
//

#include "solve_p083.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP083()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p083_matrix.txt");
    string line;
    vector<vector<uint>> matrix;
    vector<vector<ll>> path_lengths;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        stringstream ss(line);
        string value;
        matrix.push_back(vector<uint>());
        path_lengths.push_back(vector<ll>());
        while (getline(ss, value, ','))
        {
            matrix.back().push_back(stoul(value));
            path_lengths.back().push_back(-1);
        }
    }
    input.close();

    ull dim = matrix.size();

    set<pair<uint,uint>> unsolved_nodes, solved_nodes;
    path_lengths[0][0] = matrix[0][0];
    for (uint row = 0; row < dim; ++row)
    {
        for (uint col = 0; col < dim; ++col)
        {
            unsolved_nodes.insert(pair<uint,uint>(row, col));
        }
    }

    while (!unsolved_nodes.empty())
    {
        ll best_path = -1;
        pair<uint,uint> current_node;
        for (auto unsolved_neighbor : unsolved_nodes)
        {
            ll neighbor_length = path_lengths[unsolved_neighbor.first][unsolved_neighbor.second];
            if (neighbor_length == -1)
                continue;
            if (best_path == -1 || neighbor_length < best_path)
            {
                best_path = neighbor_length;
                current_node = unsolved_neighbor;
            }
        }

        unsolved_nodes.erase(current_node);
        uint row = current_node.first, col = current_node.second;
        auto top = pair<uint,uint>(row - 1, col);
        auto bottom = pair<uint,uint>(row + 1, col);
        auto left = pair<uint,uint>(row, col - 1);
        auto right = pair<uint,uint>(row, col + 1);
        if (row > 0 && (unsolved_nodes.find(top) != unsolved_nodes.end()))
        {
            ll candidate = path_lengths[row][col] + matrix[top.first][top.second];
            if (path_lengths[top.first][top.second] == -1 || candidate < path_lengths[top.first][top.second])
                path_lengths[top.first][top.second] = candidate;
        }
        if (row < dim - 1 && (unsolved_nodes.find(bottom) != unsolved_nodes.end()))
        {
            ll candidate = path_lengths[row][col] + matrix[bottom.first][bottom.second];
            if (path_lengths[bottom.first][bottom.second] == -1 || candidate < path_lengths[bottom.first][bottom.second])
                path_lengths[bottom.first][bottom.second] = candidate;
        }
        if (col > 0 && (unsolved_nodes.find(left) != unsolved_nodes.end()))
        {
            ll candidate = path_lengths[row][col] + matrix[left.first][left.second];
            if (path_lengths[left.first][left.second] == -1 || candidate < path_lengths[left.first][left.second])
                path_lengths[left.first][left.second] = candidate;
        }
        if (col < dim - 1 && (unsolved_nodes.find(right) != unsolved_nodes.end()))
        {
            ll candidate = path_lengths[row][col] + matrix[right.first][right.second];
            if (path_lengths[right.first][right.second] == -1 || candidate < path_lengths[right.first][right.second])
                path_lengths[right.first][right.second] = candidate;
        }
    }

    ll solution = path_lengths.back().back();
    cout << "P083 solution: " << solution << endl;
}