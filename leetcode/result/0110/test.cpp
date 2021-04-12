#include <iostream>

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
    bool isBalanced(TreeNode* root) {
        return (-1 != helper(root));
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
    }
};

int main() {
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1,a,nullptr);
    TreeNode* root = new TreeNode(1,b,nullptr);

    Solution s;

    std::cout << s.maxDepth(root) << std::endl;
    return 0;
}
