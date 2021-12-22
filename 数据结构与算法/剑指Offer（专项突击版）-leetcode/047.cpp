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

void printTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }

}


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (sumTree(root) == 0) {
            root = nullptr;
        }
        return root;
    }

    int sumTree(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int sumLeft = sumTree(node->left);
        if (sumLeft == 0) {
            node->left = nullptr;
        }
        int sumRight = sumTree(node->right);
        if (sumRight == 0) {
            node->right = nullptr;
        }

        return node->val + sumLeft + sumRight;
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

    cout << s.findBottomLeftValue(l0) << endl;


    return 0;
}
