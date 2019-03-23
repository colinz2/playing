//
// Created by colin on 2018/11/13.
//

#ifndef PROJECT_LEETCODE_H
#define PROJECT_LEETCODE_H

#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdlib>

using namespace std;

#endif //PROJECT_LEETCODE_H

template <typename T>
inline void PrintVector(vector<T> v) {
    for (auto c : v) {
        cout << c << " ";
    }
    cout << endl;
    //copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}