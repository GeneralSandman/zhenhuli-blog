


# Balanced Binary Tree

## Link

https://leetcode.com/problems/balanced-binary-tree


## Description

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the left and right subtrees of _every_ node differ in
> height by no more than 1.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)
            Input: root = [3,9,20,null,null,15,7]    Output: true    

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)
            Input: root = [1,2,2,3,3,null,null,4,4]    Output: false    

**Example 3:**
            Input: root = []    Output: true    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 5000]`.
  * `-104 <= Node.val <= 104`


**Tags:** Tree, Depth-first Search, Recursion

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/balanced-binary-tree


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

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
    bool isBalanced(TreeNode* root) {
        return -1 != helper(root);
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);


        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }

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
