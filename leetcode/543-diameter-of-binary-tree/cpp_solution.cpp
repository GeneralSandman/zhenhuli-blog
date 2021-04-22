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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);

        diameter = max(left + right, diameter);

        return 1 + max(left, right);
    }
};

int main() {
    Solution s;

    return 0;
}
