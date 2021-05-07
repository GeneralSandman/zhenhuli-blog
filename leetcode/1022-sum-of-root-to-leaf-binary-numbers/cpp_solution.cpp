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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return helper(root, 0);
    }

    int helper(TreeNode* root, int val = 0) {
        if (root == nullptr) {
            return 0;
        }

        val = val * 2 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        } else {
            return helper(root->left, val) + helper(root->right, val);
        }
    }
};

int main() {
    Solution s;

    return 0;
}
