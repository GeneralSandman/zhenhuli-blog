


# Binary Tree Right Side View

## Link

https://leetcode.com/problems/binary-tree-right-side-view


## Description

Given the `root` of a binary tree, imagine yourself standing on the **right
side** of it, return _the values of the nodes you can see ordered from top to
bottom_.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)
            Input: root = [1,2,3,null,5,null,4]    Output: [1,3,4]    

**Example 2:**
            Input: root = [1,null,3]    Output: [1,3]    

**Example 3:**
            Input: root = []    Output: []    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`


**Tags:** Tree, Depth-first Search, Breadth-first Search, Recursion, Queue

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-right-side-view


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }

    void helper(TreeNode* root, vector<int> &result, int level) {
        if (root == nullptr) {
            return;
        }

        if (result.size() <= level) {
            result.push_back(root->val);
        }
        
        helper(root->right, result, level+1);
        helper(root->left, result, level+1);
    }

};

int main() {

    TreeNode* l31 = new TreeNode(4,nullptr,nullptr);
    TreeNode* l32 = new TreeNode(5,nullptr,nullptr);

    TreeNode* l21 = new TreeNode(2,l31,l32);
    TreeNode* l22 = new TreeNode(3,nullptr,nullptr);

    TreeNode* l1 = new TreeNode(1,l21,l22);

    Solution s;
    vector<int> result = s.rightSideView(l1);

    for(auto v : result) {
        cout << v << " ";
    }
    cout << endl;

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
