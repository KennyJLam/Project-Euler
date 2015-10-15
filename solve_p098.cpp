//
// Created by KLam on 10/14/2015.
//

#include "solve_p098.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include "math_utils.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

// This code is a disaster but it's fast and it works
void euler::SolveP098()
{
    ifstream input("C:/Dev/Project-Euler/inputs/p098_words.txt");
    string value;
    vector<string> words;
    while (input.good())
    {
        getline(input, value, ',');
        words.push_back(value.substr(1, value.size() - 2));
    }
    input.close();

    map<multiset<char>,vector<string>> word_map;
    for (string word : words)
    {
        multiset<char> letters;
        for (char c : word)
        {
            letters.insert(c);
        }
        if (word_map.find(letters) == word_map.end())
            word_map[letters] = vector<string>();
        word_map[letters].push_back(word);
    }

    vector<vector<string>> word_index;
    for (auto iter = word_map.begin(); iter != word_map.end();)
    {
        if (iter->second.size() > 1)
            word_index.push_back(move((iter++)->second));
        else
            ++iter;
    }
    ull max_len = accumulate(word_index.begin(), word_index.end(), 0ull,
                             [] (ull init, const vector<string>& v) { return max(init, v.front().size()); });


    ull max_number = pow_int(10ull, (int)max_len);
    map<ull,map<multiset<char>,set<ull>>> square_maps;
    for (ull i = 1;;++i)
    {
        ull square = i * i;
        if (square >= max_number)
            break;
        multiset<char> digits;
        ull temp = square;
        while (temp > 0)
        {
            digits.insert((char)(temp % 10));
            temp /= 10;
        }
        if (square_maps.find(digits.size()) == square_maps.end())
            square_maps[digits.size()] = map<multiset<char>,set<ull>>();
        if (square_maps[digits.size()].find(digits) == square_maps[digits.size()].end())
            square_maps[digits.size()][digits] = set<ull>();
        square_maps[digits.size()][digits].insert(square);
    }

    map<ull,vector<set<ull>>> square_indices;
    for (auto& kvp : square_maps)
    {
        vector<set<ull>> square_index;
        for (auto iter = kvp.second.begin(); iter != kvp.second.end();)
        {
            if (iter->second.size() > 1)
                square_index.push_back(move((iter++)->second));
            else
                ++iter;
        }
        if (square_index.size() > 0)
            square_indices[kvp.first] = move(square_index);
    }

    map<pair<string,string>,pair<ull,ull>> anagram_pairs;
    for (const vector<string>& anagrams : word_index)
    {
        if (square_indices.find(anagrams.front().size()) == square_indices.end())
            continue;
        const vector<set<ull>>& square_index = square_indices[anagrams.front().size()];

        for (ull i = 0; i < anagrams.size(); ++i)
        {
            const string& anagram = anagrams[i];
            for (const set<ull>& square_set : square_index)
            {
                for (ull square : square_set)
                {
                    map<char,char> letter_digit_map;
                    set<char> used_digits;
                    ull temp = square;
                    bool conflict = false;
                    for (auto iter = anagram.rbegin(); iter != anagram.rend(); ++iter)
                    {
                        char digit = (char)(temp % 10);
                        if (letter_digit_map.find(*iter) == letter_digit_map.end())
                        {
                            if (used_digits.find(digit) != used_digits.end())
                            {
                                conflict = true;
                                break;
                            }
                            letter_digit_map[*iter] = digit;
                            used_digits.insert(digit);
                        }
                        else if (letter_digit_map[*iter] != digit)
                        {
                            conflict = true;
                            break;
                        }
                        temp /= 10;
                    }
                    if (conflict)
                        break;

                    for (ull j = 0; j < anagrams.size(); ++j)
                    {
                        if (i == j)
                            continue;
                        const string& comp_anagram = anagrams[j];
                        ull square_candidate = 0;
                        for (string::const_iterator iter = comp_anagram.begin(); iter != comp_anagram.end(); ++iter)
                        {
                            square_candidate = 10 * square_candidate + letter_digit_map[*iter];
                        }
                        if (square_set.find(square_candidate) != square_set.end())
                        {
                            auto key = pair<string,string>(anagram, comp_anagram);
                            auto squares = pair<ull,ull>(square, square_candidate);
                            if (anagram_pairs.find(key) == anagram_pairs.end())
                                anagram_pairs[key] = squares;
                            else if (max(squares.first, squares.second) > max(anagram_pairs[key].first, anagram_pairs[key].second))
                                anagram_pairs[key] = squares;
                        }
                    }
                }
            }
        }
    }
    ull max_square = accumulate(anagram_pairs.begin(), anagram_pairs.end(), 0ull,
        [] (ull init, const pair<pair<string,string>,pair<ull,ull>>& kvp) { return max(init, max(kvp.second.first, kvp.second.first)); });
    ull solution = max_square;
    cout << "P098 solution: " << solution << endl;
}
