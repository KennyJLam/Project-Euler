//
// Created by KLam on 10/12/2015.
//

#include "solve_p093.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <utility>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    void recurse_calculate(stack<pair<int,int>>& calc_stack, const vector<char>& digits, int index, set<uint>& values);
    bool next_combination(vector<char>& digits);
}

void euler::recurse_calculate(stack<pair<int,int>>& calc_stack, const vector<char>& digits, int index, set<uint>& values)
{
    if (calc_stack.size() == 1 && index == 4)
    {
        auto calc = calc_stack.top();
        if (calc.first == 0)
            return;
        if (calc.first < 0)
        {
            calc.first *= -1;
            calc.second *= -1;
        }
        if (calc.second < 0)
            return;
        if (calc.first < calc.second || calc.first % calc.second != 0)
            return;
        values.insert((uint)(calc.first / calc.second));
    }
    else if (calc_stack.empty())
    {
        calc_stack.push(pair<int,int>(digits[index], 1));
        recurse_calculate(calc_stack, digits, index + 1, values);
        calc_stack.pop();
    }
    else
    {
        if (index < 4)
        {
            calc_stack.push(pair<int,int>(digits[index], 1));
            recurse_calculate(calc_stack, digits, index + 1, values);
            calc_stack.pop();
        }
        if (calc_stack.size() >= 2)
        {
            auto a  = calc_stack.top();
            calc_stack.pop();
            auto b = calc_stack.top();
            calc_stack.pop();

            // Addition
            if (a.first == 0)
                calc_stack.push(pair<int,int>(b.first, b.second));
            else if (b.first == 0)
                calc_stack.push(pair<int,int>(a.first, a.second));
            else if (a.second == b.second)
                calc_stack.push(pair<int,int>(a.first + b.first, a.second));
            else
                calc_stack.push(pair<int,int>(a.first * b.second + b.first * a.second, a.second * b.second));
            recurse_calculate(calc_stack, digits, index, values);
            calc_stack.pop();

            //Subtraction
            if (b.first != 0) // One zero case already taken care of by addition
            {
                if (a.first * b.second == b.first * a.second)
                    calc_stack.push(pair<int,int>(0, 1));
                else if (a.first == 0)
                    calc_stack.push(pair<int,int>(-b.first, b.second));
                else if (a.second == b.second)
                    calc_stack.push(pair<int,int>(a.first - b.first, a.second));
                else
                    calc_stack.push(pair<int,int>(a.first * b.second - b.first * a.second, a.second * b.second));

                recurse_calculate(calc_stack, digits, index, values);
                calc_stack.pop();
            }

            //Multiplication
            if (a.first == 0 || b.first == 0)
                calc_stack.push(pair<int,int>(0, 1));
            else
                calc_stack.push(pair<int,int>(a.first * b.first, a.second * b.second));
            recurse_calculate(calc_stack, digits, index, values);
            calc_stack.pop();

            //Division
            if ( a.first != 0 && b.first != 0) // Zero cases already taken care of by multiplication
            {
                calc_stack.push(pair<int,int>(a.first * b.second, a.second * b.first));
                recurse_calculate(calc_stack, digits, index, values);
                calc_stack.pop();
            }

            calc_stack.push(b);
            calc_stack.push(a);
        }
    }
}

bool euler::next_combination(vector<char>& digits)
{
    for (ll i = 0; i < digits.size(); ++i)
    {
        ll n = digits.size() - i - 1;
        if (digits[n] < 9 - i)
        {
            ++digits[n];
            for (ll j = n + 1; j < digits.size(); ++j)
            {
                digits[j] = (char)(digits[j - 1] + 1);
            }
            return true;
        }
    }
    return false;
}

void euler::SolveP093()
{
    vector<char> digits { 1, 2, 3, 4 };
    vector<char> best_digits;
    uint best_n = 0;

    do
    {
        set<uint> values;

        do
        {
            stack<pair<int,int>> calc_stack;
            recurse_calculate(calc_stack, digits, 0, values);
        }
        while (next_permutation(digits.begin(), digits.end()));

        uint n = 0;
        for (uint value : values)
        {
            if (value == n + 1)
                ++n;
            else
                break;
        }
        if (n > best_n)
        {
            best_n = n;
            best_digits = digits;
        }
    }
    while (next_combination(digits));

    string result = "";
    for (char digit : best_digits)
    {
        result.push_back(digit + '0');
    }
    string solution = result;
    cout << "P093 solution: " << solution << endl;
}
