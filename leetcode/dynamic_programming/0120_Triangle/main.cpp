//
// Created by colin on 2018-12-10.
//

//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
//例如，给定三角形：
//
//[
//    [2],
//    [3,4],
//    [6,5,7],
//    [4,1,8,3]
//]
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
//
//说明：
//如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

#include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector <vector<int>> &triangle) {

        int n = triangle.size();
        for (int i = 1; i < n; i++) {

            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; j++)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }

        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};

int main() {

    vector <vector<int>> triangle = {{2},
                                     {3, 4},
                                     {6, 5, 7},
                                     {4, 1, 8, 3}};
    cout << Solution().minimumTotal(triangle) << endl;

    return 0;
}