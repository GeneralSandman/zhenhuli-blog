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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        return helper(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int helper(TreeNode* root, int target) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        if (root->val == target) {
            count = 1;
        }

        count += helper(root->left, target - root->val);
        count += helper(root->right, target - root->val);
        return count;
    }
};


int main() {
    Solution s;

    return 0;
}
