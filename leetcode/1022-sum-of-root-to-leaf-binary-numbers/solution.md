


# Sum of Root To Leaf Binary Numbers

## Link

https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers


## Description

You are given the `root` of a binary tree where each node has a value `0` or
`1`.  Each root-to-leaf path represents a binary number starting with the most
significant bit.  For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then
this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from
the root to that leaf.

Return _the sum of these numbers_. The answer is **guaranteed** to fit in a
**32-bits** integer.



**Example 1:**

![](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-
numbers.png)
            Input: root = [1,0,1,0,1,0,1]    Output: 22    Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22    

**Example 2:**
            Input: root = [0]    Output: 0    

**Example 3:**
            Input: root = [1]    Output: 1    

**Example 4:**
            Input: root = [1,1]    Output: 3    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 1000]`.
  * `Node.val` is `0` or `1`.


**Tags:** Tree

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers


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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return helper(root, 0);
    }

    int helper(TreeNode* root, int val = 0) {
        if (root == nullptr) {
            return 0;
        }

        val = val * 2 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        } else {
            return helper(root->left, val) + helper(root->right, val);
        }
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
