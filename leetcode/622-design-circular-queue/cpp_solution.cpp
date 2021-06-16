#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k): size(0), maxSize(k), i(0), j(-1), q(vector<int>(k, 0)) {}
    
    bool enQueue(int value) {
        if(size == maxSize) return false;
        if(++j == maxSize) j = 0;
        q[j] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        if(++i == maxSize) i = 0;
        --size;
        return true;
    }
    
    int Front() {
        return size == 0 ? -1 : q[i];
    }
    
    int Rear() {
        return size == 0 ? -1 : q[j];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
    
    int size;
    const int maxSize;
    int i;
    int j;
    vector<int> q;
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

int main() {
    Solution s;

    return 0;
}
