


# Valid Parentheses

## Link

https://leetcode.com/problems/valid-parentheses


## Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`,
`'['` and `']'`, determine if the input string is valid.

An input string is valid if:

  1. Open brackets must be closed by the same type of brackets.
  2. Open brackets must be closed in the correct order.



**Example 1:**
            Input: s = "()"    Output: true    

**Example 2:**
            Input: s = "()[]{}"    Output: true    

**Example 3:**
            Input: s = "(]"    Output: false    

**Example 4:**
            Input: s = "([)]"    Output: false    

**Example 5:**
            Input: s = "{[]}"    Output: true    



**Constraints:**

  * `1 <= s.length <= 104`
  * `s` consists of parentheses only `'()[]{}'`.


**Tags:** String, Stack

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/valid-parentheses


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> loop;

        for(int i=0;i<s.length();i+=1){
             if (loop.size() == 0) {
                 loop.push(s[i]);
                 continue;
             }

             if (helper(loop.top(), s[i])) {
                 loop.pop();
             } else {
                 loop.push(s[i]);
             }
        }

        return loop.size() == 0;
    }

    bool helper(char o, char n) {
        if ((o=='[' && n == ']') || (o=='{' && n == '}') || (o=='(' && n == ')')) {
            return true;
        }
        return false;
    }
};

int main() {

    Solution s;

    vector<string> a = {"()", "()[]{}", "{[]}", "[}", "({[)"};

    for(int i = 0;i<a.size();i++) {
        std::cout << s.isValid(a[i]) << std::endl;
    }

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
