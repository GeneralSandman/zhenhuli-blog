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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) {
            return true;
        }

        if(left == nullptr || right == nullptr) {
            return false;
        }

        return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
    }
};

int main() {
    Solution s;

    return 0;
}
