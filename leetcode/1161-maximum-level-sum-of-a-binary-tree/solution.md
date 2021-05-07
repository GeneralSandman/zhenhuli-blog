


# Maximum Level Sum of a Binary Tree

## Link

https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree


## Description

Given the `root` of a binary tree, the level of its root is `1`, the level of
its children is `2`, and so on.

Return the **smallest** level `x` such that the sum of all the values of nodes
at level `x` is **maximal**.



**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)
            Input: root = [1,7,0,7,-8,null,null]    Output: 2    Explanation:    Level 1 sum = 1.    Level 2 sum = 7 + 0 = 7.    Level 3 sum = 7 + -8 = -1.    So we return the level with the maximum sum which is level 2.    

**Example 2:**
            Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]    Output: 2    



**Constraints:**

  * The number of nodes in the tree is in the range `[1, 104]`.
  * `-105 <= Node.val <= 105`


**Tags:** Tree, Breadth-first Search

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree


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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        map<int,int> hashTable;
        int maxVal = INT_MIN;
        int minLevel = 1;
        helper(root, 1, hashTable);

        for(auto i = hashTable.begin(); i != hashTable.end(); i++) {
            if (i->second > maxVal) {
                maxVal = i->second;
                minLevel = i->first;
            }
        }

        return minLevel;
    }

    void helper(TreeNode* root, int level, map<int,int> &hashTable) {
        if (root == nullptr) {
            return;
        }

        hashTable[level] += root->val;
        helper(root->left, level + 1, hashTable);
        helper(root->right, level + 1, hashTable);
    }
};

int main() {
    Solution s;

    TreeNode* n31 = new TreeNode(7);
    TreeNode* n32 = new TreeNode(-8);

    TreeNode* n21 = new TreeNode(7, n31, n32);
    TreeNode* n22 = new TreeNode(0);

    TreeNode* n11 = new TreeNode(2, n21, n22);

    cout << s.maxLevelSum(n11) << endl;

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
