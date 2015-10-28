//
// Created by KLam on 10/28/2015.
//

#ifndef PROJECT_EULER_PARTITION_GENERATOR_H
#define PROJECT_EULER_PARTITION_GENERATOR_H

#include <vector>

namespace euler
{
    template<typename T>
    class PartitionGenerator
    {
    public:
        PartitionGenerator(T value);

        bool Next();

        T value() const;
        const std::vector<T>& partition() const;
        ~PartitionGenerator();
    private:
        std::vector<T> partition_;
        T value_;
    };

    template<typename T>
    PartitionGenerator<T>::PartitionGenerator(T value) : value_(value), partition_(value, 1) { }

    template<typename T>
    PartitionGenerator<T>::~PartitionGenerator() { }

    template<typename T>
    T PartitionGenerator<T>::value() const { return value_; }

    template<typename T>
    const std::vector<T>& PartitionGenerator<T>::partition() const { return partition_; }

    template<typename T>
    bool PartitionGenerator<T>::Next()
    {
        if (partition_.size() == 1)
            return false;

        auto last_i = partition_.size() - 1;
        auto prev_i = partition_.size() - 2;
        if (partition_[last_i] <= partition_[prev_i] + 1)
        {
            partition_[prev_i] += partition_[last_i];
            partition_.pop_back();
            return true;
        }

        --partition_[last_i];
        ++partition_[prev_i];

        T remainder = partition_[last_i];
        while (remainder >= 2 * partition_[prev_i])
        {
            remainder -= partition_[prev_i];
            partition_.back() = partition_[prev_i];
            partition_.push_back(remainder);
        }

        return true;
    }
}

#endif //PROJECT_EULER_PARTITION_GENERATOR_H
