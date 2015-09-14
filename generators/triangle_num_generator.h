//
// Created by KLam on 9/14/2015.
//

#ifndef PROJECT_EULER_TRIANGLE_NUM_GENERATOR_H
#define PROJECT_EULER_TRIANGLE_NUM_GENERATOR_H
#include <set>

namespace euler
{
    template<typename T>
    class TriangleNumGenerator
    {
    public:
        TriangleNumGenerator(T floor = 0);
        T Next();
        T Next(T floor);
        bool IsTriangular(T value);
        T current() const;
        ~TriangleNumGenerator();
    private:
        T generate_new_triangle_num();
        void generate_new_triangle_nums(T floor);
        T current_;
        T max_;
        unsigned long long max_index_;
        std::set<T> triangle_nums_;
    };

    template<typename T>
    TriangleNumGenerator<T>::TriangleNumGenerator(T floor) : current_(0), max_(0), max_index_(0)
    {
        generate_new_triangle_nums(floor);
    }

    template<typename T>
    TriangleNumGenerator<T>::~TriangleNumGenerator() { }

    template<typename T>
    T TriangleNumGenerator<T>::current() const { return current_; }

    template<typename T>
    T TriangleNumGenerator<T>::Next()
    {
        return Next(current_);
    }
    // Returns the first pentagonal number strictly greater than floor
    template<typename T>
    T TriangleNumGenerator<T>::Next(T floor)
    {
        if (floor >= max_)
            generate_new_triangle_nums(floor);
        return current_ = *(triangle_nums_.upper_bound(floor));
    }

    template<typename T>
    bool TriangleNumGenerator<T>::IsTriangular(T value)
    {
        if (value > max_)
            generate_new_triangle_nums(value);
        return triangle_nums_.find(value) != triangle_nums_.end();
    }

    template<typename T>
    void TriangleNumGenerator<T>::generate_new_triangle_nums(T floor)
    {
        T i = max_;
        while (i <= floor)
        {
            i = generate_new_triangle_num();
        }
        max_ = i;
    }

    template<typename T>
    T TriangleNumGenerator<T>::generate_new_triangle_num()
    {
        ++max_index_;
        T triangle_num = max_index_ * (max_index_ + 1) / 2;
        triangle_nums_.insert(triangle_num);
        return triangle_num;
    }
}

#endif //PROJECT_EULER_TRIANGLE_NUM_GENERATOR_H
