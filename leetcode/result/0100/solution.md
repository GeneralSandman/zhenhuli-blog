

# Leetcode

Leetcode 题目描述

100. Same Tree

https://leetcode.com/problems/same-tree/

<!-- tabs:start -->

#### ** C++ **

``` cpp

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

import "fmt"

func main() {
	a := &TreeNode{
		Val:1,
	}
	b := &TreeNode{
		Val:1,
		Left:a,
	}
	root := &TreeNode{
		Val:1,
		Left:b,
	}

	fmt.Println(maxDepth(root))
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

func maxDepth(root *TreeNode) int {
    if root == nil {
		return 0
	}
	return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

```

#### ** Scala **

``` scala

class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
  var value: Int = _value
  var left: TreeNode = _left
  var right: TreeNode = _right
}

object Solution {
    def maxDepth(root: TreeNode): Int = {
       if (root == null)
         return 0
      return scala.math.max(maxDepth(root.left), maxDepth(root.right)) + 1
    }




    def main(args: Array[String]): Unit = {
       val a = new TreeNode(0)
       val b = new TreeNode(1, a)
       val root = new TreeNode(1, b)

       println(maxDepth(root))
   }
}

```

<!-- tabs:end -->
