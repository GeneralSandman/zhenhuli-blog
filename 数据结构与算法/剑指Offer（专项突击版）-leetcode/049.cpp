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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }

    void helper(TreeNode* node, int oldValue, int &sum) {
        if(node == nullptr) {
            return;
        }

        if(node->left == nullptr && node->right == nullptr) {
            sum = sum + oldValue * 10 + node->val;
            return;
        } 
        
        if (node->left != nullptr) {
            helper(node->left, oldValue * 10 + node->val, sum);
        } 
        if (node->right != nullptr) {
            helper(node->right, oldValue * 10 + node->val, sum);
        }
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

    // l2_2->left = l3_0;

    cout << s.sumNumbers(l0) << endl;


    return 0;
}
