


# Evaluate Reverse Polish Notation

## Link

https://leetcode.com/problems/evaluate-reverse-polish-notation


## Description

Evaluate the value of an arithmetic expression in [Reverse Polish
Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or
another expression.

**Note** that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the
expression would always evaluate to a result, and there will not be any
division by zero operation.



**Example 1:**
            
            Input: tokens = ["2","1","+","3","*"]    
            Output: 9    
            Explanation: ((2 + 1) * 3) = 9    

**Example 2:**
            
            Input: tokens = ["4","13","5","/","+"]    
            Output: 6    
            Explanation: (4 + (13 / 5)) = 6    

**Example 3:**
            
            Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]    
            Output: 22    
            Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5    = ((10 * (6 / (12 * -11))) + 17) + 5    = ((10 * (6 / -132)) + 17) + 5    = ((10 * 0) + 17) + 5    = (0 + 17) + 5    = 17 + 5    = 22    



**Constraints:**

  * `1 <= tokens.length <= 104`
  * `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.


**Tags:** Stack

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/evaluate-reverse-polish-notation


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

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> evals;

        for(int i =0; i< tokens.size();i+=1) {
            
            string token = tokens[i];
            int val = 0;
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                val = atoi(tokens[i].c_str());
                evals.push(val);
                continue;
            }

            int b = evals.top();evals.pop();
            int a = evals.top();evals.pop();

            if (token == "+") {
                val = a + b;
            } else if (token == "-") {
                val = a - b;
            } else if (token == "*") {
                val = a * b;
            } else if (token == "/") {
                val = a / b;
            }
            evals.push(val);
        }


        return evals.top();
    }
};

int main() {
    Solution s;

    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << s.evalRPN(tokens) << endl;
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
