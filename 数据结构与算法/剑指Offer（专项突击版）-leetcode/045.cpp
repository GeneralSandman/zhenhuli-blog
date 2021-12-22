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
    int findBottomLeftValue(TreeNode* root) {

        int result_level = -1;
        int result_index = -1;
        int result = 0;

        helperDfs(root, result, result_level, result_index, 0, 0);

        return result;
    }

    void helperDfs(TreeNode* node, int &result, int &result_level, int &result_index, int level, int index) {
        if (node == nullptr) {
            return;
        }

        // 更深层
        if (level > result_level) {
            result_level = level;
            result = node->val;
        }

        // 较左边
        if (index < result_index) {
            result_index = index;
            result = node->val;
        }

        helperDfs(node->left, result, result_level, result_index, level+1, index+1);
        helperDfs(node->right, result, result_level, result_index, level+1, index+2);
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
