


# Path Sum II

## Link

https://leetcode.com/problems/path-sum-ii


## Description

Given the `root` of a binary tree and an integer `targetSum`, return all
**root-to-leaf** paths where each path's sum equals `targetSum`.

A **leaf** is a node with no children.



**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)
            Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22    Output: [[5,4,11,2],[5,8,4,5]]    

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)
            Input: root = [1,2,3], targetSum = 5    Output: []    

**Example 3:**
            Input: root = [1,2], targetSum = 0    Output: []    



**Constraints:**

  * The number of nodes in the tree is in the range `[0, 5000]`.
  * `-1000 <= Node.val <= 1000`
  * `-1000 <= targetSum <= 1000`


**Tags:** Tree, Depth-first Search

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/path-sum-ii


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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        vector<int> path;
        int leftSum = targetSum;
        helper(root, targetSum, leftSum, path, result);
        return result;
    }

    void helper(TreeNode* root, int targetSum, int leftSum, vector<int> path, vector<vector<int>>& result){
        if (root == nullptr) {
            return;
        }

        leftSum -= root->val;
        path.push_back(root->val);

        if (leftSum == 0){
            if (root->left == nullptr && root->right == nullptr) {
                result.push_back(path);
            }
        }

        helper(root->left, targetSum, leftSum, path, result);
        helper(root->right, targetSum, leftSum, path, result);
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
