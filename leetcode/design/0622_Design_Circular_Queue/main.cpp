//
// Created by colin on 2019-03-25.
//

//MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
//circularQueue.enQueue(1);  // return true
//circularQueue.enQueue(2);  // return true
//circularQueue.enQueue(3);  // return true
//circularQueue.enQueue(4);  // return false, the queue is full
//circularQueue.Rear();  // return 3
//circularQueue.isFull();  // return true
//circularQueue.deQueue();  // return true
//circularQueue.enQueue(4);  // return true
//circularQueue.Rear();  // return 4

#include "leetcode.h"

class MyCircularQueue {

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size_ = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data_.push_back(value);
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        data_.erase(data_.begin());
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data_.front();
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data_.back();
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return data_.size() == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return data_.size() == size_;
    }

private:
    vector<int> data_;
    size_t size_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    MyCircularQueue* cq = new MyCircularQueue(3);
    cout <<  cq->enQueue(1) << endl;  // return true
    cout <<  cq->enQueue(2) << endl;  // return true
    cout <<  cq->enQueue(3) << endl;  // return true
    cout <<  cq->enQueue(4) << endl;  // return false, the queue is full
    cout <<  cq->Rear()     << endl;  // return 3
    cout <<  cq->isFull()   << endl;  // return true
    cout <<  cq->deQueue()  << endl;  // return true
    cout <<  cq->enQueue(4) << endl;  // return true
    cout <<  cq->Rear()     << endl;  // return 4
}