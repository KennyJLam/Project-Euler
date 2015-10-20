//
// Created by KLam on 10/19/2015.
//

#include "solve_p102.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

void euler::SolveP102()
{
    vector<vector<pair<int,int>>> points;
    ifstream input("C:/Dev/Project-Euler/inputs/p102_triangles.txt");
    string line;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        points.push_back(vector<pair<int,int>>());
        stringstream ss(line);
        string value;
        while (ss.good())
        {
            getline(ss, value, ',');
            int x = stoi(value);
            getline(ss, value, ',');
            int y = stoi(value);
            points.back().push_back(make_pair(x,y));
        }
        sort(points.back().begin(), points.back().end());
    }
    input.close();

    ull match_count = 0;
    for (const auto& point_set : points)
    {
        double left_mid_m = ((double)point_set[1].second - point_set[0].second) / (point_set[1].first - point_set[0].first);
        double left_mid_b = point_set[0].second - left_mid_m * point_set[0].first;
        double left_right_m = ((double)point_set[2].second - point_set[0].second) / (point_set[2].first - point_set[0].first);
        double left_right_b = point_set[0].second - left_right_m * point_set[0].first;
        if ((left_mid_b > 0 && left_right_b > 0) || (left_mid_b < 0 && left_right_b < 0))
            continue;
        double mid_right_m = ((double)point_set[2].second - point_set[1].second) / (point_set[2].first - point_set[1].first);
        double mid_right_b = point_set[1].second - mid_right_m * point_set[1].first;
        if ((mid_right_b > 0 && left_right_b > 0) || (mid_right_b < 0 && left_right_b < 0))
            continue;
        ++match_count;
    }

    ull solution = match_count;
    cout << "P102 solution: " << solution << endl;
}
