//
// Created by colin on 2018-12-10.
//

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？
//
//
//
//例如，上图是一个7 x 3 的网格。有多少可能的路径？
//
//说明：m 和 n 的值均不超过 100。
//
//示例 1:
//
//输入: m = 3, n = 2
//输出: 3
//解释:
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向右 -> 向下
//2. 向右 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向右
//        示例 2:
//
//输入: m = 7, n = 3
//输出: 28

#include "leetcode.h"

class Solution {
public:
    //n行， m列
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths;
        vector<int> row(m + 1, 1);
        for (int i = 0; i <= n; i++) {
            paths.push_back(row);
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <=m; j++) {
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }
        return paths[n][m];
    }
};

int main() {
    cout << Solution().uniquePaths(7, 3) << endl;
}