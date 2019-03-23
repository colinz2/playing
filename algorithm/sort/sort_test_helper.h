//
// Created by colin on 2018/11/13.
//

#ifndef PROJECT_SORT_TEST_HELPER_H
#define PROJECT_SORT_TEST_HELPER_H

#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <algorithm>

#include "clock_time.h"

namespace sort_test_helper {

    int *GetRandomNumArray(size_t size, int l, int r) {
        int *array = new int[size];
        srandom(time(nullptr));

        for (auto i = 0; i < size; i++) {
            array[i] = random() % (r - l) + l;
        }
        return array;
    }

    template<typename T>
    T* CopyArray(T arr[], size_t n) {
        T* a = new T[n];
        std::copy(arr, arr + n, a);
        return a;
    }

    template<typename T>
    void PrintArrary(T arr[], size_t n) {
        for (auto i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    bool IsSorted(T arr[], size_t n) {
        for (auto i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    class SortTestRun {
        typedef std::function<void(T[], size_t)> sort_fun_t;
    public:
        explicit SortTestRun(const sort_fun_t &sort, T arr[], size_t n, const char *str) : clock() {
            std::cout << str << std::endl;
            clock.GatherNow();
            sort(arr, n);
            clock.PrintDuration();
            assert(IsSorted(arr, n));
        }

    private:
        ClockTime clock;
    };

    template<typename T>
    void TestSort(void (*sort)(T[], size_t), T arr[], size_t n, const char *str) {
        ClockTime clock;
        std::cout << str << std::endl;
        clock.GatherNow();
        sort(arr, n);
        clock.PrintDuration();
        assert(IsSorted(arr, n));
    }


}

#endif //PROJECT_SORT_TEST_HELPER_H
