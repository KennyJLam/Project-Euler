//
// Created by KLam on 10/19/2015.
//

#include "solve_p101.h"
#include <iostream>
#include <algorithm>
#include "math_utils.h"
#include "big_int.h"

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

using namespace std;

namespace euler
{
    void lu_decomp(const vector<vector<ll>>& matrix, vector<vector<double>>& mat_L, vector<vector<double>>& mat_U);
    vector<double> forward_sub(const vector<vector<double>>& mat_L, const vector<ll>& b);
    vector<double> backward_sub(const vector<vector<double>>& mat_U, const vector<double>& b);
}

void euler::lu_decomp(const vector<vector<ll>>& matrix, vector<vector<double>>& mat_L, vector<vector<double>>& mat_U)
{
    mat_L.clear();
    for (ull i = 0; i < matrix.size(); ++i)
    {
        mat_U.push_back(vector<double>());
        for (ull j = 0; j < matrix.size(); ++j)
        {
            mat_U.back().push_back(matrix[i][j]);
        }
        mat_L.push_back(vector<double>(matrix.size(), 0));
        mat_L.back()[i] = 1;
    }
    for (ull k = 0; k < matrix.size() - 1; ++k)
    {
        for (ull j = k + 1; j < matrix.size(); ++j)
        {
            mat_L[j][k] = ((double)mat_U[j][k]) / mat_U[k][k];
            for (ull i = k; i < matrix.size(); ++i)
            {
                mat_U[j][i] = mat_U[j][i] - mat_L[j][k] * mat_U[k][i];
            }
        }
    }
}

vector<double> euler::forward_sub(const vector<vector<double>>& mat_L, const vector<ll>& b)
{
    vector<double> x(b.size(), 0);

    for (ll i = 0; i < x.size(); ++i)
    {
        double sum = 0;
        for (ll j = 0; j < i; ++j)
        {
            sum += mat_L[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / mat_L[i][i];
    }
    return x;
}

vector<double> euler::backward_sub(const vector<vector<double>>& mat_U, const vector<double>& b)
{
    vector<double> x(b.size(), 0);

    for (ll i = x.size() - 1; i >= 0; --i)
    {
        double sum = 0;
        for (ll j = i + 1; j < x.size(); ++j)
        {
            sum += mat_U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / mat_U[i][i];
    }
    return x;
}

void euler::SolveP101()
{
    ull bad_sum = 0;
    const ull order = 10;
    vector<ll> b;
    vector<vector<ll>> matrix;
    for (ull n = 1; n <= order; ++n)
    {
        ll u = 1 - n + n * n - pow_int(n, 3) + pow_int(n, 4) - pow_int(n, 5)
               + pow_int(n, 6) - pow_int(n, 7) + pow_int(n, 8) - pow_int(n, 9) + pow_int(n, 10);
        b.push_back(u);
        for (ull r = 0; r < n - 1; ++r)
        {
            matrix[r].push_back(0);
        }
        matrix.push_back(vector<ll>(n, 0));

        for (uint r = 0; r < matrix.size(); ++r)
        {
            for (uint c = 0; c < matrix.size(); ++c)
            {
                matrix[r][c] = (ll)pow_int(r + 1, c);
            }
        }

        vector<vector<double>> mat_L, mat_U;
        lu_decomp(matrix, mat_L, mat_U);
        vector<double> y = forward_sub(mat_L, b);
        vector<double> x = backward_sub(mat_U, y);
        ll bad = 0;
        for (ull i = 0; i < x.size(); ++i)
        {
            bad += ((ll)(x[i] + (x [i] > 0 ? 0.5 : -0.5))) * pow_int(n + 1, i);
        }
        bad_sum += bad;
    }

    ull solution = bad_sum;
    cout << "P101 solution: " << solution << endl;
}
