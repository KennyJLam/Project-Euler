//
// Created by KLam on 9/22/2015.
//

#include "solve_p061.h"
#include <iostream>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

namespace euler
{
    bool recurse_search(uint key, vector<uint>& matches, set<uint>& shapes, map<uint,map<uint,set<uint>*>>& index);
}

bool euler::recurse_search(uint key, vector<uint>& matches, set<uint>& shapes, map<uint,map<uint,set<uint>*>>& index)
{
    if (key < 10)
        return false;
    for (uint shape = 3; shape <= 8; ++shape)
    {
        if (shapes.find(shape) != shapes.end())
            continue;
        if (index[shape].find(key) == index[shape].end())
            continue;
        shapes.insert(shape);
        for (uint value : *index[shape][key])
        {
            matches.push_back(value);
            if (matches.size() == 6 && matches.front() / 100 == value % 100)
                return true;
            if (recurse_search(value % 100, matches, shapes, index))
                return true;
            matches.pop_back();
        }
        shapes.erase(shape);
    }
    return false;
}

void euler::SolveP061()
{
    map<uint,map<uint,set<uint>*>> index;
    map<uint,set<uint>*> triangles, squares, pentagons, hexagons, heptagons, octagons;
    index[3] = triangles;
    index[4] = squares;
    index[5] = pentagons;
    index[6] = hexagons;
    index[7] = heptagons;
    index[8] = octagons;
    const uint min = 1000;
    const uint max = 9999;

    for (uint n = 1;;++n)
    {
        uint triangle = n * (n + 1) / 2;
        if (triangle > max)
            break;
        if (triangle > min)
        {
            uint key = triangle / 100;
            if (index[3].find(key) == index[3].end())
                index[3][key] = new set<uint>();
            index[3][key]->insert(triangle);
        }
        uint square = n * n;
        if (square > min)
        {
            uint key = square / 100;
            if (index[4].find(key) == index[4].end())
                index[4][key] = new set<uint>();
            index[4][key]->insert(square);
        }
        uint pentagon = n * (3 * n - 1) / 2;
        if (pentagon > min)
        {
            uint key = pentagon / 100;
            if (index[5].find(key) == index[5].end())
                index[5][key] = new set<uint>();
            index[5][key]->insert(pentagon);
        }
        uint hexagon = n * (2 * n - 1);
        if (hexagon > min)
        {
            uint key = hexagon / 100;
            if (index[6].find(key) == index[6].end())
                index[6][key] = new set<uint>();
            index[6][key]->insert(hexagon);
        }
        uint heptagon = n * (5 * n - 3) / 2;
        if (heptagon > min)
        {
            uint key = heptagon / 100;
            if (index[7].find(key) == index[7].end())
                index[7][key] = new set<uint>();
            index[7][key]->insert(heptagon);
        }
        uint octagon = n * (3 * n - 2);
        if (octagon > min)
        {
            uint key = octagon / 100;
            if (index[8].find(key) == index[8].end())
                index[8][key] = new set<uint>();
            index[8][key]->insert(octagon);
        }
    }

    vector<uint> matches;
    set<uint> shapes;
    shapes.insert(8);
    for (uint n = 1;;++n)
    {
        uint octagon = n * (3 * n - 2);
        if (octagon < 1000)
            continue;
        if (octagon > 9999)
            break;
        matches.push_back(octagon);
        if (recurse_search(octagon % 100, matches, shapes, index))
            break;
        matches.pop_back();
    }

    uint sum = 0;
    for (uint match : matches)
    {
        sum += match;
    }

    ull solution = sum;
    cout << "P061 solution: " << solution << endl;
}