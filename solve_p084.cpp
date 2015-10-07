//
// Created by KLam on 10/6/2015.
//

#include "solve_p084.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include <sstream>


typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    class ChanceGenerator
    {
    public:
        ChanceGenerator();
        uint NewPosition(uint position);
    private:
        vector<uint> card_results_;
        const uint num_cards_ = 16;
        uint current_ ;
    };

    class ChestGenerator
    {
    public:
        ChestGenerator();
        uint NewPosition(uint position);
    private:
        vector<uint> card_results_;
        const uint num_cards_ = 16;
        uint current_ ;
    };
}

euler::ChanceGenerator::ChanceGenerator() : card_results_(), current_(0)
{
    for (uint i = 1; i <= num_cards_; ++i)
    {
        card_results_.push_back(i);
    }
    random_shuffle(card_results_.begin(), card_results_.end());
}

uint euler::ChanceGenerator::NewPosition(uint position)
{
    uint card_result = card_results_[current_];
    ++current_;
    current_ %= num_cards_;

    switch (card_result)
    {
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 24;
        case 5:
            return 39;
        case 6:
            return 5;
        case 7:
        case 8:
            if (position >= 35 || position < 5)
                return 5;
            else if (position < 15)
                return 15;
            else if (position < 25)
                return 25;
            else
                return 35;
        case 9:
            if (position < 12 || position >= 28)
                return 12;
            else
                return 28;
        case 10:
            return position - 3;
        default:
            return position;
    }
}

euler::ChestGenerator::ChestGenerator() : card_results_(), current_(0)
{
    for (uint i = 1; i <= num_cards_; ++i)
    {
        card_results_.push_back(i);
    }
    random_shuffle(card_results_.begin(), card_results_.end());
}

uint euler::ChestGenerator::NewPosition(uint position)
{
    uint card_result = card_results_[current_];
    ++current_;
    current_ %= num_cards_;

    switch (card_result)
    {
        case 1:
            return 0;
        case 2:
            return 10;
        default:
            return position;
    }
}

// Got the correct answer but was unable to fully replicate the test case
void euler::SolveP084()
{
    const uint num_trials = 1000000;
    const uint num_dice_sides = 4;
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<> ud(0, num_dice_sides);

    ChanceGenerator chance_gen;
    ChestGenerator chest_gen;
    const uint num_squares = 40;
    vector<uint> square_counts(num_squares, 0);

    uint num_consecutive_doubles = 0;
    uint current_position = 0;
    bool prev_double = false;
    for (uint i = 0; i < num_trials; ++i)
    {
        uint roll1 = (uint)ud(rng) + 1;
        uint roll2 = (uint)ud(rng) + 1;
        if (roll1 == roll2)
        {
            if (prev_double || num_consecutive_doubles == 0)
                ++num_consecutive_doubles;
            prev_double = true;
        }
        else
        {
            num_consecutive_doubles = 0;
            prev_double = false;
        }

        if (num_consecutive_doubles == 3)
        {
            num_consecutive_doubles = 0;
            prev_double = false;
            current_position = 10;
        }
        else
        {
            current_position += (roll1 + roll2);
            current_position %= num_squares;
            if (current_position == 30)
                current_position = 10;
            else if (current_position == 7 || current_position == 22 || current_position == 36)
                current_position = chance_gen.NewPosition(current_position);
            if (current_position == 2 || current_position == 17 || current_position == 33)
                current_position = chest_gen.NewPosition(current_position);
        }
        ++square_counts[current_position];
    }

    set<pair<uint,uint>, greater<pair<uint,uint>>> square_ranks;
    for (uint i = 0; i < square_counts.size(); ++i)
    {
        square_ranks.insert(pair<uint,uint>(square_counts[i], i));
    }

    stringstream ss;
    uint i = 0;
    for (auto p : square_ranks)
    {
        if (p.second < 10)
            ss << '0';
        ss << p.second;
        //cout << ((double)p.first) / num_trials << endl;
        ++i;
        if (i == 3)
            break;
    }
    string solution = ss.str();
    cout << "P084 solution: " << solution << endl;
}