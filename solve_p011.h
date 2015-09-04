//
// Created by KLam on 8/28/2015.
//

#ifndef PROJECT_EULER_SOLVE_P011_H
#define PROJECT_EULER_SOLVE_P011_H

namespace euler
{
    void SolveP011();

    class ProductGrid
    {
    public:
        ProductGrid(int* grid_values, int dim);
        int SearchMaxHorizontal(int sub_len);
        int SearchMaxVertical(int sub_len);
        int SearchMaxTlBrDiagonal(int sub_len);
        int SearchMaxTrBlDiagonal(int sub_len);
        ~ProductGrid();
    private:
        int searchMaxInRow(int row, int sub_len);
        int searchMaxInColumn(int column, int sub_len);
        int searchMaxInTlBrDiagonal(int diagonal, int sub_len);
        int searchMaxInTrBlDiagonal(int diagonal, int sub_len);
        int** grid_;
        int dim_;
    };
}

#endif //PROJECT_EULER_SOLVE_P011_H
