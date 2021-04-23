


# Binary Tree Zigzag Level Order Traversal

## Link

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal


## Description

Given the `root` of a binary tree, return _the zigzag level order traversal of
its nodes ' values_. (i.e., from left to right, then right to left for the
next level and alternate between).



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
            Input: root = [3,9,20,null,null,15,7]    Output: [[3],[20,9],[15,7]]    

**Example 2:**
            Input: root = [1]    Output: [[1]]    

**Example 3:**
            Input: root = []    Output: []    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 2000]`.
  * `-100 <= Node.val <= 100`


**Tags:** Stack, Tree, Breadth-first Search

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal


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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == nullptr) {
            return result;
        }

        queue<TreeNode*> queueTree;

        queueTree.push(root);

        bool leftToRight = true;
        while(queueTree.size()) {
            int size = queueTree.size();
            vector<int> level(size);
            for(int i=0;i<size;i+=1) {
                
                int index = leftToRight ? i : size - i - 1;

                TreeNode* front = queueTree.front();
                queueTree.pop();
                level[index] = front->val;

                if(front->left) {
                    queueTree.push(front->left);
                }

                if(front->right) {
                    queueTree.push(front->right);
                }

            }

            leftToRight = !leftToRight;

            result.push_back(level);
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
