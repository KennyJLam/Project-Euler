//
// Created by KLam on 9/21/2015.
//

#include "solve_p059.h"
#include <iostream>
#include <fstream>

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

void euler::SolveP059()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p059_cipher.txt");
    string cipher;
    string value;
    while (input.good())
    {
        getline(input, value, ',');
        char c = value.length() == 1 ? value[0] - '0' : ((char)10 * (value[0] - '0') + value[1] - '0');
        cipher.push_back(c);
    }
    input.close();

    string key = "aaa";
    string text;
    for (;;)
    {
        text = cipher;

        for (uint i = 0; i < text.length(); i += key.length())
        {
            for (uint j = 0; j < key.length(); ++j)
            {
                if (i < text.length() - j)
                    text[i + j] ^= key[j];
            }
        }

        if (text.find("the") != string::npos &&
                text.find("and") != string::npos &&
                text.find("there") != string::npos &&
                text.find("was") != string::npos &&
                text.find("is") != string::npos)
            break;

        ++key[key.length() - 1];
        for (int i = key.length() - 1; i >= 0; --i)
        {
            if (key[i] > 'z')
            {
                key[i] = 'a';
                if (i >= 1)
                    ++key[i - 1];
            }
        }
    }

    ull sum = 0;
    for (char c : text)
    {
        sum += c;
    }

    ull solution = sum;
    cout << "P059 solution: " << solution << endl;
}