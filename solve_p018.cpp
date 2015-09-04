//
// Created by KLam on 8/31/2015.
//

#include "solve_p018.h"
#include <iostream>

typedef unsigned long long ull;
using namespace std;

void euler::SolveP018()
{
    const unsigned int numbers[120] = {
            75,
            95, 64,
            17, 47, 82,
            18, 35, 87, 10,
            20,  4, 82, 47, 65,
            19,  1, 23, 75,  3, 34,
            88,  2, 77, 73,  7, 63, 67,
            99, 65,  4, 28,  6, 16, 70, 92,
            41, 41, 26, 56, 83, 40, 80, 70, 33,
            41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
            53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
            70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
            91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
            63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
             4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23
    };

    const int num_layers = 15;
    int index = 0;
    unsigned int** pyramid = new unsigned int*[num_layers];
    for (int i = 0; i < num_layers; ++i)
    {
        pyramid[i] = new unsigned int[i + 1];
        for (int j = 0; j <= i; ++j)
        {
            pyramid[i][j] = numbers[index];
            ++index;
        }
    }

    ull layer[num_layers];
    for (int i = 0; i < num_layers; ++i)
    {
        layer[i] = 0;
    }
    for (int i = num_layers - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            layer[j] += (ull)pyramid[i][j];
        }
        for (int j = 0; j < i; ++j)
        {
            layer[j] = layer[j] > layer[j + 1] ? layer[j] : layer[j + 1];
        }
    }

    ull solution = layer[0];
    cout << "P018 solution: " << solution << endl;

    for (int i = 0; i < num_layers; ++i)
    {
        delete[] pyramid[i];
    }
    delete[] pyramid;
}