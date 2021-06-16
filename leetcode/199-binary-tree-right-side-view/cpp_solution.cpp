#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }

    void helper(TreeNode* root, vector<int> &result, int level) {
        if (root == nullptr) {
            return;
        }

        if (result.size() <= level) {
            result.push_back(root->val);
        }
        
        helper(root->right, result, level+1);
        helper(root->left, result, level+1);
    }

};

int main() {

    TreeNode* l31 = new TreeNode(4,nullptr,nullptr);
    TreeNode* l32 = new TreeNode(5,nullptr,nullptr);

    TreeNode* l21 = new TreeNode(2,l31,l32);
    TreeNode* l22 = new TreeNode(3,nullptr,nullptr);

    TreeNode* l1 = new TreeNode(1,l21,l22);

    Solution s;
    vector<int> result = s.rightSideView(l1);

    for(auto v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
