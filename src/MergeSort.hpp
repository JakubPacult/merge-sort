#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>

template <typename T>
class MergeSort {
private:
    void merge(std::vector<T>& arr, int left, int mid, int right);
    void sortRecursive(std::vector<T>& arr, int left, int right);

public:
    void sort(std::vector<T>& arr);
};

#endif // MERGESORT_HPP