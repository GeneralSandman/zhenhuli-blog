


# Min Stack

## Link

https://leetcode.com/problems/min-stack


## Description

Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Implement the `MinStack` class:

  * `MinStack()` initializes the stack object.
  * `void push(val)` pushes the element `val` onto the stack.
  * `void pop()` removes the element on the top of the stack.
  * `int top()` gets the top element of the stack.
  * `int getMin()` retrieves the minimum element in the stack.



**Example 1:**
            
            **Input**    
            ["MinStack","push","push","push","getMin","pop","top","getMin"]    
            [[],[-2],[0],[-3],[],[],[],[]]        

            **Output**    
            [null,null,null,null,-3,null,0,-2]    

            **Explanation**    
            MinStack minStack = new MinStack();    
            minStack.push(-2);    
            minStack.push(0);    
            minStack.push(-3);    
            minStack.getMin(); // return -3    
            minStack.pop();    
            minStack.top();    // return 0    
            minStack.getMin(); // return -2    



**Constraints:**

  * `-231 <= val <= 231 - 1`
  * Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
  * At most `3 * 104` calls will be made to `push`, `pop`, `top`, and `getMin`.


**Tags:** Stack, Design

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/min-stack


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

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


```

#### ** Go **

``` go

this is just a code

```

#### ** Scala **

``` scala

this is just a code

```

<!-- tabs:end -->
