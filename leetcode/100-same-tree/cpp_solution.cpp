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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode* a1 = new TreeNode(1);
    TreeNode* b1 = new TreeNode(2,a1,nullptr);
    TreeNode* root1 = new TreeNode(3,b1,nullptr);

    TreeNode* a2 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2,a2,nullptr);
    TreeNode* root2 = new TreeNode(3,b2,nullptr);

    Solution s;
    std::cout << s.isSameTree(root1,root2) << std::endl;
    std::cout << s.isSameTree(b1,b2) << std::endl;
    std::cout << s.isSameTree(a1,a2) << std::endl;
    std::cout << s.isSameTree(a1,b2) << std::endl;
    return 0;
}
