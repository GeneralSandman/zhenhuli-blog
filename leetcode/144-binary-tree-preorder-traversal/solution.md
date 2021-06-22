


# Binary Tree Preorder Traversal

## Link

https://leetcode.com/problems/binary-tree-preorder-traversal


## Description

Given the `root` of a binary tree, return _the preorder traversal of its nodes
' values_.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
            Input: root = [1,null,2,3]    Output: [1,2,3]    

**Example 2:**
            Input: root = []    Output: []    

**Example 3:**
            Input: root = [1]    Output: [1]    

**Example 4:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)
            Input: root = [1,2]    Output: [1,2]    

**Example 5:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)
            Input: root = [1,null,2]    Output: [1,2]    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`



**Follow up:** Recursive solution is trivial, could you do it iteratively?


**Tags:** Stack, Tree

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-preorder-traversal


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        
        TreeNode* node = root;
        while(node || !s.empty()) {

            while(node) {
                result.push_back(node->val);
                s.push(node);
                node = node->left;
            }

            if(!s.empty()) {
                TreeNode* top = s.top();
                s.pop();

                node = top->right;
            }

        }

        return result;
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
