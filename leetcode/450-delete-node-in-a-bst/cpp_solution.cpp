#include <iostream>
#include <vector>
#include <map>
#include <climits>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 删除当前节点，
            if(root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else if(root->left == nullptr && root->right != nullptr) {
                return root->right;
            } else if(root->left != nullptr && root->right == nullptr) {
                return root->left;
            } else {
                int maxVal = findMaxVal(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left, maxVal);
            }
        }
        return root;
    }

public:
    int findMaxVal(TreeNode* root) {
        if(root == nullptr) {
            return INT_MIN;
        }
        
        while(root->right != nullptr) {
            root = root->right;
        }

        return root->val;

    }
};

int main() {
    Solution s;

    return 0;
}
