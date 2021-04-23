


# Reverse Linked List

## Link

https://leetcode.com/problems/reverse-linked-list


## Description

Given the `head` of a singly linked list, reverse the list, and return _the
reversed list_.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)
            Input: head = [1,2,3,4,5]    Output: [5,4,3,2,1]    

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)
            Input: head = [1,2]    Output: [2,1]    

**Example 3:**
            Input: head = []    Output: []    



**Constraints:**

  * The number of nodes in the list is the range `[0, 5000]`.
  * `-5000 <= Node.val <= 5000`



**Follow up:** A linked list can be reversed either iteratively or
recursively. Could you implement both?


**Tags:** Linked List

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/reverse-linked-list


- [ ] **C++**
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
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;
        ListNode* newHead = nullptr;

        while(head) {
            newHead = head;
            head = head->next;
            newHead->next = pre;
            pre = newHead;
        }

        return newHead;
    }

    ListNode* reverseList2(ListNode* head) {

        if(head == nullptr) {
            return nullptr;
        }


    }

    void helper(ListNode* cur, ListNode* next) {

        helper(cur, next);
    }
};

int main() {
    Solution s;

    ListNode* n4 = new ListNode(4);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    ListNode* n0 = new ListNode(0, n1);

    ListNode * tmp = n0;
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }


    tmp = s.reverseList(n0);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    tmp = s.reverseList2(n0);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
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
