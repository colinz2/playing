//
// Created by colin on 2018-12-07.
//

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) -- 将元素 x 推入栈中。
//pop() -- 删除栈顶的元素。
//top() -- 获取栈顶元素。
//getMin() -- 检索栈中的最小元素。
//示例:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.

#include "leetcode.h"

#include <stack>
#include <utility> //pair

class MinStack {
private:
    std::stack<std::pair<int,int>> s_;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        int min = x;
        if (s_.size() > 0) {
            if (min > getMin())
                min = getMin();
        }
        s_.push(std::pair<int, int>(x, min));
    }

    void pop() {
        if (s_.size() > 0)
            s_.pop();
    }

    int top() {
        return s_.top().first;
    }

    int getMin() {
        return s_.top().second;
    }
};


int main() {
    MinStack* minStack = new MinStack();
    minStack->push(3);
//    minStack->push(4);
//    minStack->push(100);
//    minStack->push(10);
//    minStack->push(1);
    cout << "min: " << minStack->getMin() << endl;
    cout << "top: " << minStack->top() << endl;
    //minStack->pop();
    //minStack->pop();
    cout << "min: " << minStack->getMin() << endl;
}