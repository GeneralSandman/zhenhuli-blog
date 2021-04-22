


# Maximum Depth of Binary Tree

## Link

https://leetcode.com/problems/maximum-depth-of-binary-tree


## Description

Given the `root` of a binary tree, return _its maximum depth_.

A binary tree's **maximum depth**  is the number of nodes along the longest
path from the root node down to the farthest leaf node.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)
            Input: root = [3,9,20,null,null,15,7]    Output: 3    

**Example 2:**
            Input: root = [1,null,2]    Output: 2    

**Example 3:**
            Input: root = []    Output: 0    

**Example 4:**
            Input: root = [0]    Output: 1    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 104]`.
  * `-100 <= Node.val <= 100`


**Tags:** Tree, Depth-first Search, Recursion

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/maximum-depth-of-binary-tree


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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};

int main() {
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1,a,nullptr);
    TreeNode* root = new TreeNode(1,b,nullptr);

    Solution s;

    std::cout << s.maxDepth(root) << std::endl;
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




    def main(args: Array[String]) {
       val a = new TreeNode(0)
       val b = new TreeNode(1, a)
       val root = new TreeNode(1, b)

       println(maxDepth(root))
   }
}

```

<!-- tabs:end -->
