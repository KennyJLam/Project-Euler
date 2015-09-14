//
// Created by KLam on 9/14/2015.
//

#ifndef PROJECT_EULER_HEXAGONAL_GENERATOR_H
#define PROJECT_EULER_HEXAGONAL_GENERATOR_H

#include <set>

namespace euler
{
    template<typename T>
    class HexagonalGenerator
    {
    public:
        HexagonalGenerator(T floor = 0);
        T Next();
        T Next(T floor);
        bool IsHexagonal(T value);
        T current() const;
        ~HexagonalGenerator();
    private:
        T generate_new_hexagonal();
        void generate_new_hexagonals(T floor);
        T current_;
        T max_;
        unsigned long long max_index_;
        std::set<T> hexagonals_;
    };

    template<typename T>
    HexagonalGenerator<T>::HexagonalGenerator(T floor) : current_(0), max_(0), max_index_(0)
    {
        generate_new_hexagonals(floor);
    }

    template<typename T>
    HexagonalGenerator<T>::~HexagonalGenerator() { }

    template<typename T>
    T HexagonalGenerator<T>::current() const { return current_; }

    template<typename T>
    T HexagonalGenerator<T>::Next()
    {
        return Next(current_);
    }
    // Returns the first pentagonal number strictly greater than floor
    template<typename T>
    T HexagonalGenerator<T>::Next(T floor)
    {
        if (floor >= max_)
            generate_new_hexagonals(floor);
        return current_ = *(hexagonals_.upper_bound(floor));
    }

    template<typename T>
    bool HexagonalGenerator<T>::IsHexagonal(T value)
    {
        if (value > max_)
            generate_new_hexagonals(value);
        return hexagonals_.find(value) != hexagonals_.end();
    }

    template<typename T>
    void HexagonalGenerator<T>::generate_new_hexagonals(T floor)
    {
        T i = max_;
        while (i <= floor)
        {
            i = generate_new_hexagonal();
        }
        max_ = i;
    }

    template<typename T>
    T HexagonalGenerator<T>::generate_new_hexagonal()
    {
        ++max_index_;
        T hexagonal = max_index_ * (2 * max_index_ - 1);
        hexagonals_.insert(hexagonal);
        return hexagonal;
    }
}

#endif //PROJECT_EULER_HEXAGONAL_GENERATOR_H
