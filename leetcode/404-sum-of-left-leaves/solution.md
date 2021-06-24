


# Sum of Left Leaves

## Link

https://leetcode.com/problems/sum-of-left-leaves


## Description

Given the `root` of a binary tree, return the sum of all left leaves.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)
            Input: root = [3,9,20,null,null,15,7]    Output: 24    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.    

**Example 2:**
            Input: root = [1]    Output: 0    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 1000]`.
  * `-1000 <= Node.val <= 1000`


**Tags:** Tree

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/sum-of-left-leaves


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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

int main() {
    Solution s;

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
