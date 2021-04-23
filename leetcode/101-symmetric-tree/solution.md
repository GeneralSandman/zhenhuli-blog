


# Symmetric Tree

## Link

https://leetcode.com/problems/symmetric-tree


## Description

Given the `root` of a binary tree, _check whether it is a mirror of itself_
(i.e., symmetric around its center).



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)
            Input: root = [1,2,2,3,4,4,3]    Output: true    

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)
            Input: root = [1,2,2,null,3,null,3]    Output: false    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 1000]`.
  * `-100 <= Node.val <= 100`



**Follow up:** Could you solve it both recursively and iteratively?


**Tags:** Tree, Depth-first Search, Breadth-first Search

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/symmetric-tree


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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) {
            return true;
        }

        if(left == nullptr || right == nullptr) {
            return false;
        }

        return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
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
