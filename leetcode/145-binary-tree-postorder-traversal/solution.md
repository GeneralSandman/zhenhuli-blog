


# Binary Tree Postorder Traversal

## Link

https://leetcode.com/problems/binary-tree-postorder-traversal


## Description

Given the `root` of a binary tree, return _the postorder traversal of its
nodes ' values_.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)
            Input: root = [1,null,2,3]    Output: [3,2,1]    

**Example 2:**
            Input: root = []    Output: []    

**Example 3:**
            Input: root = [1]    Output: [1]    

**Example 4:**

![](https://assets.leetcode.com/uploads/2020/08/28/pre3.jpg)
            Input: root = [1,2]    Output: [2,1]    

**Example 5:**

![](https://assets.leetcode.com/uploads/2020/08/28/pre2.jpg)
            Input: root = [1,null,2]    Output: [2,1]    



**Constraints:**

  * The number of the nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`



**Follow up:**

Recursive solution is trivial, could you do it iteratively?




**Tags:** Stack, Tree

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-postorder-traversal


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
