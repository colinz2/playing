//
// Created by colin on 2018/11/13.
//

#ifndef PROJECT_SORT_IMP_H
#define PROJECT_SORT_IMP_H

#include <cctype>
#include <algorithm>

//selection sort
//
template<typename T>
void InsertionSort2(T arr[], size_t n) {

    for (size_t i = 1; i < n; i++) {
        for (size_t j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                std::swap(arr[j], arr[j-1]);
            } else {
                break;
            }
        }
    }
}

template<typename T>
void InsertionSort(T arr[], size_t n) {

    for (size_t i = 1; i < n; i++) {
        T e = arr[i];
        size_t j;
        for (j = i; j > 0 && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

//quick sort
//

template<typename T>
size_t _QuickSortPartition(T arr[], size_t l, size_t r) {
    T b = arr[l];
    size_t p = l;

    for (auto i = l + 1; i <= r; i++) {
        if (arr[i] < b) {
            p++;
            std::swap(arr[p], arr[i]);
        }
    }
    std::swap(arr[p], arr[l]);
    return p;
}

template<typename T>
void _QuickSort(T arr[], size_t l, size_t r) {

    if (l >= r)
        return;

    size_t p = _QuickSortPartition(arr, l, r);
    if (p != 0)
        _QuickSort(arr, l, p - 1);
    _QuickSort(arr, p + 1, r);

}

template<typename T>
void QuickSort(T arr[], size_t n) {
    _QuickSort(arr, 0, n - 1);
}



#endif //PROJECT_SORT_IMP_H
