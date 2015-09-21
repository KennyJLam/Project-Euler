//
// Created by KLam on 9/18/2015.
//

#include "solve_p054.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

typedef unsigned long long ull;
typedef unsigned int uint;


using namespace std;

namespace euler
{
    enum PokerHands
    {
        HighCard = 0,
        OnePair,
        TwoPair,
        ThreeOfAKind,
        Straight,
        Flush,
        FullHouse,
        FourOfAKind,
        StraightFlush
    };

    uint get_rank(char rank_char)
    {
        switch (rank_char)
        {
            case 'A':
                return 14;
            case 'K':
                return 13;
            case 'Q':
                return 12;
            case 'J':
                return 11;
            case 'T':
                return 10;
            default:
                return (uint)(rank_char - '0');
        }
    }

    PokerHands get_poker_hand(const map<uint,uint>& ranks, const map<char,uint>& suits)
    {
        bool has_flush = false;
        for (auto suit : suits)
        {
            if (suit.second == 5)
            {
                has_flush = true;
                break;
            }
        }

        bool has_pair = false;
        bool has_triplet = false;
        uint prev_rank = 0;
        uint num_consecutive = 0;
        for (auto rank : ranks)
        {
            if (rank.second == 4)
                return FourOfAKind;
            if (rank.second == 3)
                has_triplet = true;
            else if (rank.second == 2)
            {
                if (has_pair)
                    return TwoPair;
                has_pair = true;
            }
            else
            {
                if (prev_rank != 0 && (rank.first - prev_rank == 1 || (rank.first == 14 && prev_rank == 5 && num_consecutive == 3)))
                    ++num_consecutive;
                else
                    num_consecutive = 0;
            }
            prev_rank = rank.first;
        }
        bool has_straight = num_consecutive == 4;
        if (has_straight && has_flush)
            return StraightFlush;
        if (has_triplet && has_pair)
            return FullHouse;
        if (has_flush)
            return Flush;
        if (has_straight)
            return Straight;
        if (has_triplet)
            return ThreeOfAKind;
        if (has_pair)
            return OnePair;
        return HighCard;
    }

    struct OrderCards
    {
        bool operator()(const pair<uint,uint>& a, const pair<uint,uint>& b) const
        {
            if (a.second < b.second)
                return true;
            return a.second == b.second && a.first < b.first;
        }
    };

    bool tie_break(const map<uint,uint>& hand1_ranks, const map<uint,uint>& hand2_ranks)
    {
        set<pair<uint,uint>, OrderCards> order1;
        set<pair<uint,uint>, OrderCards> order2;

        for (auto rank : hand1_ranks)
        {
            order1.insert(rank);
        }

        for (auto rank : hand2_ranks)
        {
            order2.insert(rank);
        }

        auto iter1 = order1.rbegin();
        auto iter2 = order2.rbegin();

        while (iter1 != order1.rend())
        {
            auto t1 = *iter1;
            auto t2 = *iter2;

            if (t1.first > t2.first)
                return true;
            else if (t1.first < t2.first)
                return false;
            ++iter1;
            ++iter2;
        }
        return false;
    }
}

// Sloppy and lazy but I really don't want to build another proper poker comparer
void euler::SolveP054()
{
    const uint hand_size = 5;
    vector<string> hands;

    ifstream input("C:/Dev/Project-Euler/inputs/p054_poker.txt");
    string value;
    while (input.good())
    {
        getline(input, value);
        if (value.length() > 0)
            hands.push_back(value);
    }
    input.close();

    uint num_wins = 0;
    for (string hand_str : hands)
    {
        map<uint, uint> hand1_ranks;
        map<char, uint> hand1_suits;
        map<uint, uint> hand2_ranks;
        map<char, uint> hand2_suits;
        for (uint i = 0; i < hand_size; ++i)
        {
            uint hand1_rank = get_rank(hand_str[i * 3]);
            uint hand2_rank = get_rank(hand_str[(i + hand_size) * 3]);
            char hand1_suit = hand_str[i * 3 + 1];
            char hand2_suit = hand_str[(i + hand_size) * 3 + 1];
            if (hand1_ranks.find(hand1_rank) == hand1_ranks.end())
                hand1_ranks[hand1_rank] = 0;
            if (hand2_ranks.find(hand2_rank) == hand2_ranks.end())
                hand2_ranks[hand2_rank] = 0;
            if (hand1_suits.find(hand1_suit) == hand1_suits.end())
                hand1_suits[hand1_suit] = 0;
            if (hand2_suits.find(hand2_suit) == hand2_suits.end())
                hand2_suits[hand2_suit] = 0;
            ++hand1_ranks[hand1_rank];
            ++hand2_ranks[hand2_rank];
            ++hand1_suits[hand1_suit];
            ++hand2_suits[hand2_suit];
        }

        PokerHands hand1 = get_poker_hand(hand1_ranks, hand1_suits);
        PokerHands hand2 = get_poker_hand(hand2_ranks, hand2_suits);

        if (hand1 > hand2 || (hand1 == hand2 && tie_break(hand1_ranks, hand2_ranks)))
            ++num_wins;
    }

    ull solution = num_wins;
    cout << "P054 solution: " << solution << endl;
}