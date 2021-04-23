


# Binary Tree Level Order Traversal

## Link

https://leetcode.com/problems/binary-tree-level-order-traversal


## Description

Given the `root` of a binary tree, return _the level order traversal of its
nodes ' values_. (i.e., from left to right, level by level).



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
            Input: root = [3,9,20,null,null,15,7]    Output: [[3],[9,20],[15,7]]    

**Example 2:**
            Input: root = [1]    Output: [[1]]    

**Example 3:**
            Input: root = []    Output: []    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 2000]`.
  * `-1000 <= Node.val <= 1000`


**Tags:** Tree, Breadth-first Search

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-level-order-traversal


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, 0, result);
        return result;
    }

    void helper(TreeNode* root, int level,vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        if (result.size() <= level) {
            vector<int> tmp;
            result.push_back(tmp);
        }
        result[level].push_back(root->val);
        helper(root->left, level+1, result);
        helper(root->right, level+1, result);
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
