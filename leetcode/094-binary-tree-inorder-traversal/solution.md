


# Binary Tree Inorder Traversal

## Link

https://leetcode.com/problems/binary-tree-inorder-traversal


## Description

Given the `root` of a binary tree, return _the inorder traversal of its nodes
' values_.



**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
            Input: root = [1,null,2,3]    Output: [1,3,2]    

**Example 2:**
            Input: root = []    Output: []    

**Example 3:**
            Input: root = [1]    Output: [1]    

**Example 4:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)
            Input: root = [1,2]    Output: [2,1]    

**Example 5:**

![](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)
            Input: root = [1,null,2]    Output: [1,2]    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`



**Follow up:**

Recursive solution is trivial, could you do it iteratively?




**Tags:** Hash Table, Stack, Tree

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-inorder-traversal


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` go

#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, std::vector<int>& result) {
        if(root == nullptr) {
            return;
        }

        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
};

int main() {
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1,a,nullptr);
    TreeNode* root = new TreeNode(2,b,nullptr);

    Solution s;
    std::vector<int> result = s.inorderTraversal(root);

    for(int i = 0;i<result.size();i+=1) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
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




    def main(args: Array[String]) : Unit = {
       val a = new TreeNode(0)
       val b = new TreeNode(1, a)
       val root = new TreeNode(1, b)
       println("------")
   }
}

```

<!-- tabs:end -->
