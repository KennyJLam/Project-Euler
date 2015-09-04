//
// Created by KLam on 8/31/2015.
//

#include "solve_p017.h"
#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;

int euler::GetNumLettersSingleDigit(int target)
{
    switch (target)
    {
        case 1: // "one"
        case 2: // "two"
        case 6: // "six"
            return 3;
        case 4: // "four"
        case 5: // "five"
        case 9: // "nine"
            return 4;
        case 3: // "three"
        case 7: // "seven"
        case 8: // "eight"
            return 5;
        default:
            return 0;
    }
}

int euler::GetNumLettersTeens(int target)
{
    switch (target)
    {
        case 10: // "ten"
            return 3;
        case 11: // "eleven"
        case 12: // "twelve"
            return 6;
        case 13: // "thirteen"
        case 18: // "eighteen"
            return 8;
        case 15: // "fifteen"
            return 7;
        default: // [digit] + "teen"
            return GetNumLettersSingleDigit(target % 10) + 4;
    }
}

int euler::GetNumLettersTensDigit(int target)
{
    switch (target)
    {
        case 2: // "twenty"
        case 3: // "thirty"
        case 8: // "eighty"
            return 6;
        case 4: // "forty"
        case 5: // "fifty"
            return 5;
        default: // [digit] + "ty"
            return GetNumLettersSingleDigit(target) + 2;
    }
}

int euler::GetNumLetters(int target)
{
    int number = target;
    int sum = 0;

    if (number >= 1000)
    {
        sum += GetNumLettersSingleDigit(number / 1000) + 8; // [digit] + "thousand"
        number %= 1000;
    }
    if (number >= 100)
    {
        sum += GetNumLettersSingleDigit(number / 100) + 7; // [digit] + "hundred"
        number %= 100;
        if (number > 0) // "and"
            sum += 3;
    }
    if (number >= 10)
    {
        if (number < 20)
        {
            sum += GetNumLettersTeens(number);
            return sum;
        }
        sum += GetNumLettersTensDigit(number / 10);
        number %= 10;
    }
    if (number > 0)
        sum += GetNumLettersSingleDigit(number);
    return sum;
}

void euler::SolveP017()
{
    const int max = 1000;
    int sum = 0;
    for (int i = 1; i <= max; ++i)
    {
        sum += GetNumLetters(i);
    }
    int solution = sum;
    cout << "P017 solution: " << solution << endl;
}
