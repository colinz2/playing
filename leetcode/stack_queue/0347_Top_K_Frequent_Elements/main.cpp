//
// Created by colin on 2018-12-12.
//

//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//示例 1:
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//示例 2:
//输入: nums = [1], k = 1
//输出: [1]
//说明：
//
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

// O(n log (n - k) ) ?

#include "leetcode.h"

class Solution {
public:
    //基于优先队列
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;

        for (auto &k : nums) {
            freq[k]++;
        }

        if (k < 1 || k > freq.size()) return res;

        //freq num
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto &kv : freq) {
            if (pq.size() == k) {
                if (pq.top().first < kv.second) {
                    pq.pop();
                    pq.push(make_pair(kv.second, kv.first));
                }
            } else {
                pq.push(make_pair(kv.second, kv.first));
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    //基于桶排序
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto c : nums) freq[c]++;
        for (auto &kv : freq) bucket[kv.second].push_back(kv.first);

        //容易出错，终止条件写在push_back后
        for (int i = nums.size(); i >= 0; i--) {
            for (auto c : bucket[i]) {
                res.push_back(c);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};

int main() {
    vector<int> v1 = {1,2};

    PrintVector(Solution().topKFrequent(v1, 2));
    PrintVector(Solution().topKFrequent2(v1, 2));

    //assert(Solution().topKFrequent(v1, 2) == Solution().topKFrequent2(v1, 2));
}

