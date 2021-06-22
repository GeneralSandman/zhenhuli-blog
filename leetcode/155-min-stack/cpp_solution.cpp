#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (min.empty() || min.top() >= val) {
            min.push(val);
        }
    }
    
    void pop() {
        if (s.top() == min.top()) {
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        if (s.empty()) {
            return INT_MIN;
        }
        return s.top();
    }
    
    int getMin() {
        if (min.empty()) {
            return INT_MIN;
        }
        return min.top();
    }

private:
    stack<int> s;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;    
    minStack.push(-2);    
    minStack.push(0);    
    minStack.push(-3);    
    cout << minStack.getMin() << endl; // return -3    
    minStack.pop();    
    cout << minStack.top() << endl;    // return 0    
    cout << minStack.getMin() << endl; // return -2

    return 0;
}
