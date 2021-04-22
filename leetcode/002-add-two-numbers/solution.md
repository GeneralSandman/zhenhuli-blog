


# Add Two Numbers

## Link

https://leetcode.com/problems/add-two-numbers


## Description

You are given two **non-empty** linked lists representing two non-negative
integers. The digits are stored in **reverse order** , and each of their nodes
contains a single digit. Add the two numbers and return the sum as a linked
list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
            Input: l1 = [2,4,3], l2 = [5,6,4]    Output: [7,0,8]    Explanation: 342 + 465 = 807.    

**Example 2:**
            Input: l1 = [0], l2 = [0]    Output: [0]    

**Example 3:**
            Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]    Output: [8,9,9,9,0,0,0,1]    



**Constraints:**

  * The number of nodes in each linked list is in the range `[1, 100]`.
  * `0 <= Node.val <= 9`
  * It is guaranteed that the list represents a number that does not have leading zeros.


**Tags:** Linked List, Math, Recursion

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/add-two-numbers


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }

    ListNode* helper(ListNode* l1, ListNode* l2, int val) {
        if (l1 == nullptr && l2 == nullptr && val == 0) {
            return nullptr;
        }

        int current = val;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        if (l1 != nullptr) {
            current += l1->val;
            next1 = l1->next;
        }

        if (l2 != nullptr) {
            current += l2->val;
            next2 = l2->next;
        }

        ListNode* newNode = new ListNode(current%10);

        newNode->next = helper(next1, next2, current/10);
        return newNode;
    }
};

int main_() {
    Solution s;

    ListNode *l13 = new ListNode(3);
    ListNode *l12 = new ListNode(4, l13);
    ListNode *l11 = new ListNode(2, l12);

    ListNode *l23 = new ListNode(4);
    ListNode *l22 = new ListNode(6, l23);
    ListNode *l21 = new ListNode(5, l22);

    ListNode *result = s.addTwoNumbers(l11,l21);
    while(result != nullptr) {
        cout << "listNode:" << result->val << endl;
        result = result->next;
    }

    return 0;
}

int main() {
    Solution s;

    ListNode *l17 = new ListNode(9);
    ListNode *l16 = new ListNode(9, l17);
    ListNode *l15 = new ListNode(9, l16);
    ListNode *l14 = new ListNode(9, l15);
    ListNode *l13 = new ListNode(9, l14);
    ListNode *l12 = new ListNode(9, l13);
    ListNode *l11 = new ListNode(9, l12);

    ListNode *l24 = new ListNode(9);
    ListNode *l23 = new ListNode(9, l24);
    ListNode *l22 = new ListNode(9, l23);
    ListNode *l21 = new ListNode(9, l22);

    ListNode *result = s.addTwoNumbers(l11,l21);
    while(result != nullptr) {
        cout << "listNode:" << result->val << endl;
        result = result->next;
    }

    return 0;
}

```

#### ** Go **

``` go

package main

func main() {
	
}


```

#### ** Scala **

``` scala


object Solution {
    def maxDepth(root: TreeNode): Int = {
    }




    def main(args: Array[String]): Unit = {
   }
}

```

<!-- tabs:end -->
