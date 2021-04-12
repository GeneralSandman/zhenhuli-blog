#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, std::vector<int>& result) {
        if(root == nullptr) {
            return;
        }

        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
};

int main() {
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1,a,nullptr);
    TreeNode* root = new TreeNode(2,b,nullptr);

    Solution s;
    std::vector<int> result = s.inorderTraversal(root);

    for(int i = 0;i<result.size();i+=1) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
