//
// Created by colin on 2018-12-15.
//

//不使用任何内建的哈希表库设计一个哈希集合
//
//具体地说，你的设计应该包含以下的功能
//
//add(value)：向哈希集合中插入一个值。
//contains(value) ：返回哈希集合中是否存在这个值。
//remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//
//示例:
//MyHashSet hashSet = new MyHashSet();
//hashSet.add(1);
//hashSet.add(2);
//hashSet.contains(1);    // 返回 true
//hashSet.contains(3);    // 返回 false (未找到)
//hashSet.add(2);
//hashSet.contains(2);    // 返回 true
//hashSet.remove(2);
//hashSet.contains(2);    // 返回  false (已经被删除)
//
//注意：
//所有的值都在 [1, 1000000]的范围内。
//操作的总数目在[1, 10000]范围内。
//不要使用内建的哈希集合库。

#include "leetcode.h"

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        if (set_.find(key) == set_.end()) {
            set_.insert(key);
        }
    }

    void remove(int key) {
        if (set_.find(key) != set_.end()) {
            set_.erase(key);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return set_.find(key) != set_.end();
    }

private:
    unordered_set<int> set_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */

int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(100);
    cout << obj->contains(100) << endl;
    obj->remove(100);
    cout << obj->contains(100) << endl;
}

