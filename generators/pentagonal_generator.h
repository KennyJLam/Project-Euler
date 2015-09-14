//
// Created by KLam on 9/14/2015.
//

#ifndef PROJECT_EULER_PENTAGONAL_GENERATOR_H
#define PROJECT_EULER_PENTAGONAL_GENERATOR_H

#include <set>

namespace euler
{
    template<typename T>
    class PentagonalGenerator
    {
    public:
        PentagonalGenerator(T floor = 0);
        T Next();
        T Next(T floor);
        bool IsPentagonal(T value);
        T current() const;
        ~PentagonalGenerator();
    private:
        T generate_new_pentagonals();
        void generate_new_pentagonal(T floor);
        T current_;
        T max_;
        unsigned long long max_index_;
        std::set<T> pentagonals_;
    };

    template<typename T>
    PentagonalGenerator<T>::PentagonalGenerator(T floor) : current_(0), max_(0), max_index_(0)
    {
        generate_new_pentagonal(floor);
    }

    template<typename T>
    PentagonalGenerator<T>::~PentagonalGenerator() { }

    template<typename T>
    T PentagonalGenerator<T>::current() const { return current_; }

    template<typename T>
    T PentagonalGenerator<T>::Next()
    {
        return Next(current_);
    }
    // Returns the first pentagonal number strictly greater than floor
    template<typename T>
    T PentagonalGenerator<T>::Next(T floor)
    {
        if (floor >= max_)
            generate_new_pentagonal(floor);
        return current_ = *(pentagonals_.upper_bound(floor));
    }

    template<typename T>
    bool PentagonalGenerator<T>::IsPentagonal(T value)
    {
        if (value > max_)
            generate_new_pentagonal(value);
        return pentagonals_.find(value) != pentagonals_.end();
    }

    template<typename T>
    void PentagonalGenerator<T>::generate_new_pentagonal(T floor)
    {
        T i = max_;
        while (i <= floor)
        {
            i = generate_new_pentagonals();
        }
        max_ = i;
    }

    template<typename T>
    T PentagonalGenerator<T>::generate_new_pentagonals()
    {
        ++max_index_;
        T pentagonal = max_index_ * (3 * max_index_ - 1) / 2;
        pentagonals_.insert(pentagonal);
        return pentagonal;
    }
}




#endif //PROJECT_EULER_PENTAGONAL_GENERATOR_H
