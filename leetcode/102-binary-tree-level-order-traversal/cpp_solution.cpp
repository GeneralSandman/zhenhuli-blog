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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, 0, result);
        return result;
    }

    void helper(TreeNode* root, int level,vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        if (result.size() <= level) {
            vector<int> tmp;
            result.push_back(tmp);
        }
        result[level].push_back(root->val);
        helper(root->left, level+1, result);
        helper(root->right, level+1, result);
    }
};

int main() {
    Solution s;

    return 0;
}
