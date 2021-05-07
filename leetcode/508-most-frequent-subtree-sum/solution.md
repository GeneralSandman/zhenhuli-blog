


# Most Frequent Subtree Sum

## Link

https://leetcode.com/problems/most-frequent-subtree-sum


## Description

Given the root of a tree, you are asked to find the most frequent subtree sum.
The subtree sum of a node is defined as the sum of all the node values formed
by the subtree rooted at that node (including the node itself). So what is the
most frequent subtree sum value? If there is a tie, return all the values with
the highest frequency in any order.

**Examples 1**  
Input:
              5     /  \    2   -3    

return [2, -3, 4], since all the values happen only once, return all of them
in any order.

**Examples 2**  
Input:
              5     /  \    2   -5    

return [2], since 2 happens twice, however -5 only occur once.

**Note:** You may assume the sum of values in any subtree is in the range of
32-bit signed integer.


**Tags:** Hash Table, Tree

**Difficulty:** Medium

## 思路

[title]: https://leetcode.com/problems/most-frequent-subtree-sum


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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> hashTable;
        int maxFrequent = INT_MIN;
        helper(root, hashTable, maxFrequent);

        vector<int> result;
        for(auto i = hashTable.begin(); i != hashTable.end(); i++) {
            if (i->second == maxFrequent) {
                result.push_back(i->first);
            }
        }

        return result;
    }

    int helper(TreeNode* root, map<int,int> &hashTable, int &maxFrequent) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = root->val;
        sum += helper(root->left, hashTable, maxFrequent);
        sum += helper(root->right, hashTable, maxFrequent);
        hashTable[sum] += 1;
        maxFrequent = max(maxFrequent, hashTable[sum]);
        return sum;
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
