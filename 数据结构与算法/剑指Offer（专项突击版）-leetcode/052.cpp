#include <iostream>
#include <vector>
#include <map>
#include <climits>
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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> inorder;
        inorderAccess(root, inorder);

        TreeNode* result = inorder.front();

        TreeNode* pre = nullptr;
        while(!inorder.empty()) {
            TreeNode* cur = inorder.front();
            inorder.pop();

            cur->left = nullptr;
            cur->right = nullptr;

            if(pre != nullptr) {
                pre->left = nullptr;
                pre->right = cur;
            }

            pre = cur;
        }


        return result;


    }

    void inorderAccess(TreeNode* root, queue<TreeNode*> &inorder) {
        if(root == nullptr) {
            return;
        }

        inorderAccess(root->left, inorder);
        inorder.push(root);
        inorderAccess(root->right, inorder);
    }
};


int main() {
    Solution s;

    TreeNode *l0 = new TreeNode(1);

    TreeNode *l1_0 = new TreeNode(3);
    TreeNode *l1_1 = new TreeNode(2);

    TreeNode *l2_0 = new TreeNode(5);
    TreeNode *l2_1 = new TreeNode(3);
    TreeNode *l2_2 = new TreeNode(9);

    l0->left = l1_0;
    l0->right = l1_1;

    l1_0->left = l2_0;
    l1_0->right = l2_1;
    l1_1->left = nullptr;
    l1_1->right = l2_2;

    s.increasingBST(l0);


    return 0;
}
