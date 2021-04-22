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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int leftVal = INT_MIN;
        int rightVal = INT_MAX;

        if (root->left != nullptr) {
            leftVal = root->left->val;
        }

        if (root->right != nullptr) {
            rightVal = root->right->val;
        }

        cout << leftVal << " " << root->val << " " << rightVal << endl;

        return ((leftVal<=root->val)&&(root->val<=rightVal)&&isValidBST(root->left) && isValidBST(root->right));
    }
};


class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

int main() {
    Solution s;

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(3);

    TreeNode* r1 = new TreeNode(2, n1, n2);

    cout<<s.isValidBST(r1) << endl;





    TreeNode* n21 = new TreeNode(1);
    TreeNode* n22 = new TreeNode(3);

    TreeNode* r2 = new TreeNode(5, n21, n22);

    cout<<s.isValidBST(r2) << endl;



    TreeNode* n31 = new TreeNode(1);
    TreeNode* n32 = new TreeNode(4);

    TreeNode* r3 = new TreeNode(5, n31, n32);

    cout<<s.isValidBST(r3) << endl;


    return 0;
}
