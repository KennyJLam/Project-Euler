//
// Created by KLam on 8/26/2015.
//

#ifndef PROJECT_EULER_SOLVE_P004_H
#define PROJECT_EULER_SOLVE_P004_H

namespace euler
{
    bool CanBe3Factored(int target, int& result1, int& result2);
    void SolveP004();
    unsigned int Pow2(int exp);

    class PalindromeGenerator
    {
    public:
        PalindromeGenerator(int initial_value);
        int GetPrev();
        int current();
    private:
        int current_;
        int half_;
        int num_digits_;
        int half_digits_;
        int pow10(int exp);
    };
}

#endif //PROJECT_EULER_SOLVE_P004_H
