//
// Created by KLam on 10/23/2015.
//

#include "solve_p107.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <tuple>
#include <queue>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP107()
{
    vector<vector<ull>> graph;
    ifstream input("C:/Dev/Project-Euler/inputs/p107_network.txt");
    string line;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        graph.push_back(vector<ull>());
        stringstream ss(line);
        string value;
        while (ss.good())
        {
            getline(ss, value, ',');
            ull weight = value[0] == '-' ? 0 : stoull(value);
            graph.back().push_back(weight);
        }
    }
    input.close();

    typedef pair<pair<ull,ull>,ull> edge_t;
    auto comp = [](const edge_t& a, const edge_t& b ) { return a.second > b.second; };
    priority_queue<edge_t,vector<edge_t>, decltype(comp)> edges(comp);
    ull sum = 0;
    for (ull i = 0; i < graph.size() - 1; ++i)
    {
        for (ull j = i + 1; j < graph[i].size(); ++j)
        {
            if (graph[i][j] != 0)
            {
                edges.push(make_pair(make_pair(i, j), graph[i][j]));
                sum += graph[i][j];
            }
        }
    }

    ull min_sum = 0;
    vector<set<ull>> forest;
    for (ull k = 0; k < graph.size(); ++k)
    {
        forest.push_back(set<ull> { k });
    }
    while (forest.size() > 1)
    {
        ull vertex_a = edges.top().first.first;

        vector<set<ull>>::iterator tree_a;
        for (tree_a = forest.begin(); tree_a != forest.end(); ++tree_a)
        {
            if (tree_a->find(vertex_a) != tree_a->end())
                break;
        }
        ull vertex_b = edges.top().first.second;
        if (tree_a->find(vertex_b) == tree_a->end())
        {
            vector<set<ull>>::iterator tree_b;
            for (tree_b = forest.begin(); tree_b != forest.end(); ++tree_b)
            {
                if (tree_b->find(vertex_b) != tree_b->end())
                    break;
            }
            min_sum += edges.top().second;
            tree_a->insert(tree_b->begin(), tree_b->end());
            forest.erase(tree_b);
        }
        edges.pop();
    }

    ull solution = sum - min_sum;
    cout << "P107 solution: " << solution << endl;
}
