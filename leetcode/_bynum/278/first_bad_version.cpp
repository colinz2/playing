//
// Created by colin on 2018/11/23.
//
//你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。
//由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
//假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
//
//你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
//实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
//
//示例:
//给定 n = 5，并且 version = 4 是第一个错误的版本。
//调用 isBadVersion(3) -> false
//调用 isBadVersion(5) -> true
//调用 isBadVersion(4) -> true
//所以，4 是第一个错误的版本。

#include "../leetcode.h"

static vector<bool> gVersoinsTbl;
void InitBadVersoin(int n, int b)
{
    gVersoinsTbl.resize(n + 1);
    for (int i = 1; i < n + 1; i++) {
        gVersoinsTbl[i] = (i >= b);
    }
}

bool isBadVersion(int version)
{
    return gVersoinsTbl[version];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    InitBadVersoin(5, 3);
    PrintVector(gVersoinsTbl);
    assert(Solution().firstBadVersion(5) == 3);

    InitBadVersoin(5, 1);
    PrintVector(gVersoinsTbl);
    assert(Solution().firstBadVersion(5) == 1);


    InitBadVersoin(5, 5);
    PrintVector(gVersoinsTbl);
    assert(Solution().firstBadVersion(5) == 5);
}