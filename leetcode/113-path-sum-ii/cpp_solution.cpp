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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        vector<int> path;
        int leftSum = targetSum;
        helper(root, targetSum, leftSum, path, result);
        return result;
    }

    void helper(TreeNode* root, int targetSum, int leftSum, vector<int> path, vector<vector<int>>& result){
        if (root == nullptr) {
            return;
        }

        leftSum -= root->val;
        path.push_back(root->val);

        if (leftSum == 0){
            if (root->left == nullptr && root->right == nullptr) {
                result.push_back(path);
            }
        }

        helper(root->left, targetSum, leftSum, path, result);
        helper(root->right, targetSum, leftSum, path, result);
    }
};

int main() {
    Solution s;

    return 0;
}
