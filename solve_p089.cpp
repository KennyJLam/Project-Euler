//
// Created by Klam on 10/10/2015.
//

#include "solve_p089.h"
#include <iostream>
#include <fstream>
#include <queue>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;


void euler::SolveP089()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p089_roman.txt");
    string line;
    vector<string> numbers;
    while (input.good())
    {
        getline(input, line);
        if (line.size() == 0)
            continue;
        numbers.push_back(move(line));
    }
    input.close();

    uint save_count = 0;
    queue<char> lookback;
    for (const string& number : numbers)
    {
        string efficient_number;
        uint consecutive = 0;
        for (char c : number)
        {
            if (!lookback.empty() && c == lookback.back())
                ++consecutive;
            else
                consecutive = 1;
            lookback.push(c);
            if (lookback.size() == 6)
            {
                efficient_number.push_back(lookback.front());
                lookback.pop();
            }
            if (consecutive == 4 && c != 'M')
            {
                consecutive = 0;
                char new_char;
                switch (lookback.back())
                {
                    case 'I': new_char = 'V'; break;
                    case 'X': new_char = 'L'; break;
                    case 'C': new_char = 'D'; break;
                    default: new_char = '\0'; break;
                }
                if (lookback.size() == 5 && new_char == lookback.front())
                {
                    switch (new_char)
                    {
                        case 'V': new_char = 'X'; break;
                        case 'L': new_char = 'C'; break;
                        case 'D': new_char = 'M'; break;
                        default: new_char = '\0'; break;
                    }
                    efficient_number.push_back(lookback.back());
                    efficient_number.push_back(new_char);
                }
                else
                {
                    if (lookback.size() == 5)
                        efficient_number.push_back(lookback.front());
                    efficient_number.push_back(lookback.back());
                    efficient_number.push_back(new_char);
                }
                while (!lookback.empty()) lookback.pop();
            }
        }
        while (!lookback.empty())
        {
            efficient_number.push_back(lookback.front());
            lookback.pop();
        }
        save_count += number.size() - efficient_number.size();
    }

    ull solution = save_count;
    cout << "P089 solution: " << solution << endl;
}