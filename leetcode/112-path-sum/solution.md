


# Path Sum

## Link

https://leetcode.com/problems/path-sum


## Description

Given the `root` of a binary tree and an integer `targetSum`, return `true` if
the tree has a **root-to-leaf** path such that adding up all the values along
the path equals `targetSum`.

A **leaf** is a node with no children.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)
            Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22    Output: true    

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)
            Input: root = [1,2,3], targetSum = 5    Output: false    

**Example 3:**
            Input: root = [1,2], targetSum = 0    Output: false    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 5000]`.
  * `-1000 <= Node.val <= 1000`
  * `-1000 <= targetSum <= 1000`


**Tags:** Tree, Depth-first Search

**Difficulty:** Easy

## 思路

[title]: https://leetcode.com/problems/path-sum


- [X] **C++**
- [ ] **Go**
- [ ] **Scala**

<!-- tabs:start -->

#### ** C++ **

``` cpp

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)   return false;
        
        if(root->left==nullptr && root->right==nullptr){
            if(sum==root->val)  return true;
            else return false;
        }
        
        else if(root->left!=nullptr && root->right==nullptr){
            return hasPathSum(root->left,sum-root->val);
        }
        
        else if(root->left==nullptr && root->right!=nullptr){
            return hasPathSum(root->right,sum-root->val);
        }
        
        else{
            return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
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
