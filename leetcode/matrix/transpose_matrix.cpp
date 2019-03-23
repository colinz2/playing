//
// Created by colin on 2018/11/23.
//

//给定一个矩阵 A， 返回 A 的转置矩阵。
//矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
//示例 1：
//
//输入：[[1,2,3],[4,5,6],[7,8,9]]
//输出：[[1,4,7],[2,5,8],[3,6,9]]
//示例 2：
//
//输入：[[1,2,3],[4,5,6]]
//输出：[[1,4],[2,5],[3,6]]
//
//提示：
//1 <= A.length <= 1000
//1 <= A[0].length <= 1000

#include "../leetcode.h"

void PrintMatrx(vector<vector<int>>& x) {
    for (int i = 0; i < x.size(); i++) {
        cout << "[";
        for (int j = 0; j < x[0].size(); j++) {
            cout << x[i][j] << " ";
        }
        cout << "]\n";
    }
}

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row_num = A.size();
        int col_num = A[0].size();
        vector<vector<int>> T(col_num);

        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                T[j].push_back(A[i][j]);
            }
        }
        return T;
    }
};

int main() {
    vector<vector<int>> v1 = {{1,2,3}, {4, 5, 6}};
    vector<vector<int>> v1t = Solution().transpose(v1);
    PrintMatrx(v1);
    PrintMatrx(v1t);
}

