//
// Created by colin on 2018/11/13.
//


#include <iostream>
#include "clock_time.h"
#include "sort_test_helper.h"
#include "sort_imp.h"
#include <vector>

using namespace sort_test_helper;

template <typename T>
int BinarySearch(std::vector<T>& array, T target) {
    int left = 0;
    int right = array.size();
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (array[middle] > target) {
            right = middle - 1;
        } else if (array[middle] < target) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}


int main() {
    size_t N = 10000;

    int *array = GetRandomNumArray(N, 10, N + 99999);

    PrintArrary(array, 10);

    //SortTestRun<int>(InsertionSort<int>, array, N, "插入排序");

    //TestSort(InsertionSort, CopyArray(array, N), N, "插入排序");
    //TestSort(InsertionSort2, CopyArray(array, N), N, "插入排序2");
    TestSort(QuickSort, CopyArray(array, N), N, "快速排序");
    //TestSort(QuickSort, array, N, "快速排序");

    PrintArrary(array, 100);

//    std::vector<int> tv = {1, 2, 3, 19, 190, 1233, 1514};
//    std::cout << BinarySearch(tv, 190) << std::endl;
}
