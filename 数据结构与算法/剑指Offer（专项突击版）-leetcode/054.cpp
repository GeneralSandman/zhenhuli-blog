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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        int nodeLeftSumValue = 0;
        helperDfs1(root, sum, nodeLeftSumValue);
        changeValue(root, sum);
        return root;
    }

    void changeValue(TreeNode* node, int sum) {
        if(node == nullptr) {
            return;
        }
        node->val = sum-node->val;
        changeValue(node->left, sum);
        changeValue(node->right, sum);
    }

    void helperDfs1(TreeNode* node, int &sum, int &nodeLeftSumValue) {
        if (node == nullptr) {
            return;
        }

        helperDfs1(node->left, sum, nodeLeftSumValue);
        nodeLeftSumValue = sum;
        sum += node->val;
        node->val = nodeLeftSumValue;
        helperDfs1(node->right, sum, nodeLeftSumValue);
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

    TreeNode *l3_0 = new TreeNode(7);


    l0->left = l1_0;
    l0->right = l1_1;

    l1_0->left = l2_0;
    l1_0->right = l2_1;
    l1_1->left = nullptr;
    l1_1->right = l2_2;

    l2_2->left = l3_0;

    cout << s.convertBST(l0) << endl;


    return 0;
}
