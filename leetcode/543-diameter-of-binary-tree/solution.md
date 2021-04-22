


# Diameter of Binary Tree

## Link

https://leetcode.com/problems/diameter-of-binary-tree


## Description

Given the `root` of a binary tree, return _the length of the **diameter** of
the tree_.

The **diameter** of a binary tree is the **length** of the longest path
between any two nodes in a tree. This path may or may not pass through the
`root`.

The **length** of a path between two nodes is represented by the number of
edges between them.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)
            Input: root = [1,2,3,4,5]    Output: 3    Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].    

**Example 2:**
            Input: root = [1,2]    Output: 1    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 104]`.
  * `-100 <= Node.val <= 100`


**Tags:** Tree

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/diameter-of-binary-tree


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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);

        diameter = max(left + right, diameter);

        return 1 + max(left, right);
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
