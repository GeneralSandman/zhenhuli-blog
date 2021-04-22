


# Validate Binary Search Tree

## Link

https://leetcode.com/problems/validate-binary-search-tree


## Description

Given the `root` of a binary tree, _determine if it is a valid binary search
tree (BST)_.

A **valid BST** is defined as follows:

  * The left subtree of a node contains only nodes with keys **less than** the node's key.
  * The right subtree of a node contains only nodes with keys **greater than** the node's key.
  * Both the left and right subtrees must also be binary search trees.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
            Input: root = [2,1,3]    Output: true    

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
            Input: root = [5,1,4,null,null,3,6]    Output: false    Explanation: The root node's value is 5 but its right child's value is 4.    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 104]`.
  * `-231 <= Node.val <= 231 - 1`


**Tags:** Tree, Depth-first Search, Recursion

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/validate-binary-search-tree


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>
#include <climits>

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int leftVal = INT_MIN;
        int rightVal = INT_MAX;

        if (root->left != nullptr) {
            leftVal = root->left->val;
        }

        if (root->right != nullptr) {
            rightVal = root->right->val;
        }

        cout << leftVal << " " << root->val << " " << rightVal << endl;

        return ((leftVal<=root->val)&&(root->val<=rightVal)&&isValidBST(root->left) && isValidBST(root->right));
    }
};


class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

int main() {
    Solution s;

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(3);

    TreeNode* r1 = new TreeNode(2, n1, n2);

    cout<<s.isValidBST(r1) << endl;





    TreeNode* n21 = new TreeNode(1);
    TreeNode* n22 = new TreeNode(3);

    TreeNode* r2 = new TreeNode(5, n21, n22);

    cout<<s.isValidBST(r2) << endl;



    TreeNode* n31 = new TreeNode(1);
    TreeNode* n32 = new TreeNode(4);

    TreeNode* r3 = new TreeNode(5, n31, n32);

    cout<<s.isValidBST(r3) << endl;


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
