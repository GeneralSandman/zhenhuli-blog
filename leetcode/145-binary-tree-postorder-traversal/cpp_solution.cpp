#include <iostream>
#include <vector>
#include <map>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        
        TreeNode* node = root;
        while(node || !s.empty()) {

            while(node) {
                result.push_back(node->val);
                s.push(node);
                node = node->left;
            }

            if(!s.empty()) {
                TreeNode* top = s.top();
                s.pop();

                node = top->right;
            }

        }

        return result;
    }

};

int main() {
    Solution s;

    return 0;
}
