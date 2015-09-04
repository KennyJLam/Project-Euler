//
// Created by KLam on 8/28/2015.
//

#include "solve_p011.h"
#include <iostream>

using namespace std;
using euler::ProductGrid;

ProductGrid::ProductGrid(int *grid_values, int dim) : dim_(dim)
{
    grid_ = new int*[dim_];
    for (int i = 0; i < dim_; ++i)
    {
        grid_[i] = new int[dim_];

        for (int j = 0; j < dim_; ++j)
        {
            grid_[i][j] = grid_values[i * dim_ + j];
        }
    }
}

ProductGrid::~ProductGrid()
{
    for (int i = 0; i < dim_; ++i)
    {
        delete[] grid_[i];
    }
    delete[] grid_;
}

int ProductGrid::SearchMaxHorizontal(int sub_len)
{
    int max = 0;
    for (int row = 0; row < dim_; ++row)
    {
        int max_in_row = searchMaxInRow(row, sub_len);
        if (max_in_row > max)
            max = max_in_row;
    }
    return max;
}

int ProductGrid::searchMaxInRow(int row, int sub_len)
{
    int max = 0;
    int tail = 0, head = sub_len - 1;
    int product = 1;

    RECHECK_ZEROS:
    for (int i = 0; i < sub_len; ++i)
    {
        if (grid_[row][tail + i] == 0)
        {
            product = 1;
            tail += (i + 1);
            head += (i + 1);
            goto RECHECK_ZEROS;
        }
        product *= grid_[row][tail + i];
    }
    if (product > max)
        max = product;
    while (head < dim_ - 1)
    {
        product /= grid_[row][tail];
        ++tail;
        ++head;
        if (grid_[row][head] == 0)
        {
            product = 1;
            tail += sub_len;
            head += sub_len;
            if (head >= dim_)
                break;
            goto RECHECK_ZEROS;
        }
        product *= grid_[row][head];
        if (product > max)
            max = product;
    }

    return max;
}

int ProductGrid::SearchMaxVertical(int sub_len)
{
    int max = 0;
    for (int column = 0; column < dim_; ++column)
    {
        int max_in_column = searchMaxInColumn(column, sub_len);
        if (max_in_column > max)
            max = max_in_column;
    }
    return max;
}

int ProductGrid::searchMaxInColumn(int column, int sub_len)
{
    int max = 0;
    int tail = 0, head = sub_len - 1;
    int product = 1;

    RECHECK_ZEROS:
    for (int i = 0; i < sub_len; ++i)
    {
        if (grid_[tail + i][column] == 0)
        {
            product = 1;
            tail += (i + 1);
            head += (i + 1);
            goto RECHECK_ZEROS;
        }
        product *= grid_[tail + i][column];
    }
    if (product > max)
        max = product;
    while (head < dim_ - 1)
    {
        product /= grid_[tail][column];
        ++tail;
        ++head;
        if (grid_[head][column] == 0)
        {
            product = 1;
            tail += sub_len;
            head += sub_len;
            if (head >= dim_)
                break;
            goto RECHECK_ZEROS;
        }
        product *= grid_[head][column];
        if (product > max)
            max = product;
    }

    return max;
}

int ProductGrid::SearchMaxTlBrDiagonal(int sub_len)
{
    int max = 0;
    for (int diagonal = 0; diagonal < 2 * dim_ - 1; ++diagonal)
    {
        int max_in_diagonal = searchMaxInTlBrDiagonal(diagonal, sub_len);
        if (max_in_diagonal > max)
            max = max_in_diagonal;
    }
    return max;
}

int ProductGrid::searchMaxInTlBrDiagonal(int diagonal, int sub_len)
{
    int diagonal_len = diagonal < dim_ ? (diagonal + 1) : (2 * dim_ - diagonal - 1);
    if (sub_len > diagonal_len)
        return 0;
    int max = 0;
    int tail_row = diagonal < dim_ ? (dim_ - diagonal - 1) : 0;
    int tail_col = diagonal < dim_ ? 0 : (diagonal - dim_ + 1);
    int head_row = tail_row + sub_len - 1, head_col = tail_col + sub_len - 1;
    int product = 1;

    RECHECK_ZEROS:
    for (int i = 0; i < sub_len; ++i)
    {
        if (grid_[tail_row + i][tail_col + i] == 0)
        {
            product = 1;
            tail_row += (i + 1);
            tail_col += (i + 1);
            head_row += (i + 1);
            head_col += (i + 1);
            goto RECHECK_ZEROS;
        }
        product *= grid_[tail_row + i][tail_col + i];
    }
    if (product > max)
        max = product;
    while (head_row < dim_ - 1 && head_col < dim_ - 1)
    {
        product /= grid_[tail_row][tail_col];
        ++tail_row;
        ++tail_col;
        ++head_row;
        ++head_col;
        if (grid_[head_row][head_col] == 0)
        {
            product = 1;
            tail_row += sub_len;
            tail_col += sub_len;
            head_row += sub_len;
            head_col += sub_len;
            if (head_row >= dim_ || head_col >= dim_)
                break;
            goto RECHECK_ZEROS;
        }
        product *= grid_[head_row][head_col];
        if (product > max)
            max = product;
    }

    return max;
}

int ProductGrid::SearchMaxTrBlDiagonal(int sub_len)
{
    int max = 0;
    for (int diagonal = 0; diagonal < 2 * dim_ - 1; ++diagonal)
    {
        int max_in_diagonal = searchMaxInTrBlDiagonal(diagonal, sub_len);
        if (max_in_diagonal > max)
            max = max_in_diagonal;
    }
    return max;
}

int ProductGrid::searchMaxInTrBlDiagonal(int diagonal, int sub_len)
{
    int diagonal_len = diagonal < dim_ ? (diagonal + 1) : (2 * dim_ - diagonal - 1);
    if (sub_len > diagonal_len)
        return 0;
    int max = 0;
    int tail_row = diagonal < dim_ ? diagonal : dim_ - 1;
    int tail_col = diagonal < dim_ ? 0 : (diagonal - dim_ + 1);
    int head_row = tail_row - sub_len + 1, head_col = tail_col + sub_len - 1;
    int product = 1;

    RECHECK_ZEROS:
    for (int i = 0; i < sub_len; ++i)
    {
        if (grid_[tail_row - i][tail_col + i] == 0)
        {
            product = 1;
            tail_row -= (i + 1);
            tail_col += (i + 1);
            head_row -= (i + 1);
            head_col += (i + 1);
            goto RECHECK_ZEROS;
        }
        product *= grid_[tail_row - i][tail_col + i];
    }
    if (product > max)
        max = product;
    while (head_row > 0 && head_col < dim_ - 1)
    {
        product /= grid_[tail_row][tail_col];
        --tail_row;
        ++tail_col;
        --head_row;
        ++head_col;
        if (grid_[head_row][head_col] == 0)
        {
            product = 1;
            tail_row -= sub_len;
            tail_col += sub_len;
            head_row -= sub_len;
            head_col += sub_len;
            if (head_row < 0 || head_col >= dim_)
                break;
            goto RECHECK_ZEROS;
        }
        product *= grid_[head_row][head_col];
        if (product > max)
            max = product;
    }

    return max;
}

void euler::SolveP011()
{
    int values[400] = {
             8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8,
            49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0,
            81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65,
            52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91,
            22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
            24, 47, 32, 60, 99, 03, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
            32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
            67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21,
            24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
            21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95,
            78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80, 04, 62, 16, 14,  9, 53, 56, 92,
            16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57,
            86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
            19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40,
             4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
            88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
             4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36,
            20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16,
            20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
             1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48
    };

    ProductGrid grid(values, 20);
    const int sub_len = 4;

    int max_horizontal = grid.SearchMaxHorizontal(sub_len);
    int max_vertical = grid.SearchMaxVertical(sub_len);
    int max_tlbr_diagonal = grid.SearchMaxTlBrDiagonal(sub_len);
    int max_trbl_diagonal = grid.SearchMaxTrBlDiagonal(sub_len);
    int max = 0;
    if (max_horizontal > max)
        max = max_horizontal;
    if (max_vertical > max)
        max = max_vertical;
    if (max_tlbr_diagonal > max)
        max = max_tlbr_diagonal;
    if (max_trbl_diagonal > max)
        max = max_trbl_diagonal;

    int solution = max;
    cout << "P011 solution: " << solution << endl;
}