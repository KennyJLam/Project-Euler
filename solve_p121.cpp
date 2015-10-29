//
// Created by KLam on 10/29/2015.
//

#include "solve_p121.h"
#include <iostream>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    static double recurse_prob(uint num_wins, uint num_losses, uint num_games);
}

double euler::recurse_prob(uint num_wins, uint num_losses, uint num_games)
{
    uint threshold = num_games / 2;
    if (num_wins > threshold)
        return 1;
    if (num_losses >= num_games - threshold)
        return 0;
    double win_prob = 1.0 / (num_wins + num_losses + 2.0);
    double conditional_win = recurse_prob(num_wins + 1, num_losses, num_games);
    double conditional_loss = recurse_prob(num_wins, num_losses + 1, num_games);

    return win_prob * conditional_win + (1 - win_prob) * conditional_loss;
}

void euler::SolveP121()
{
    const uint num_games = 15;

    double p = recurse_prob(0 ,0, num_games);
    uint bet = (uint)((1 - p) / p) + 1;

    ull solution = bet;
    cout << "P121 solution: " << solution << endl;
}