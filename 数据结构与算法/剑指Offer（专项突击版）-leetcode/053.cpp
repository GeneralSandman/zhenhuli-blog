#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> inorderAccess;
        if(root == nullptr || p == nullptr) {
            return nullptr;
        }

        helper(root, inorderAccess);
        while(!inorderAccess.empty() && inorderAccess.top() != p) {
            inorderAccess.pop();
        }
        if(inorderAccess.empty()) {
            return nullptr;
        }
        inorderAccess.pop();
        if(inorderAccess.empty()) {
            return nullptr;
        }
        return inorderAccess.top();

    }

    void helper(TreeNode* root, stack<TreeNode*> &inorderAccess) {
        if(root == nullptr) {
            return;
        }

        helper(root->right, inorderAccess);
        inorderAccess.push(root);
        helper(root->left, inorderAccess);
    }
};

int main() {
    Solution s;

    return 0;
}
