#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)   return false;
        
        if(root->left==nullptr && root->right==nullptr){
            if(sum==root->val)  return true;
            else return false;
        }
        
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
        
    }
};

int main() {
    Solution s;

    return 0;
}
