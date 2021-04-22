


# Same Tree

## Link

https://leetcode.com/problems/same-tree


## Description

Given the roots of two binary trees `p` and `q`, write a function to check if
they are the same or not.

Two binary trees are considered the same if they are structurally identical,
and the nodes have the same value.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)
            Input: p = [1,2,3], q = [1,2,3]    Output: true    

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)
            Input: p = [1,2], q = [1,null,2]    Output: false    

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)
            Input: p = [1,2,1], q = [1,1,2]    Output: false    



**Constraints:**

  * The number of nodes in both trees is in the range `[0, 100]`.
  * `-104 <= Node.val <= 104`


**Tags:** Tree, Depth-first Search

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/same-tree


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode* a1 = new TreeNode(1);
    TreeNode* b1 = new TreeNode(2,a1,nullptr);
    TreeNode* root1 = new TreeNode(3,b1,nullptr);

    TreeNode* a2 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2,a2,nullptr);
    TreeNode* root2 = new TreeNode(3,b2,nullptr);

    Solution s;
    std::cout << s.isSameTree(root1,root2) << std::endl;
    std::cout << s.isSameTree(b1,b2) << std::endl;
    std::cout << s.isSameTree(a1,a2) << std::endl;
    std::cout << s.isSameTree(a1,b2) << std::endl;
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
