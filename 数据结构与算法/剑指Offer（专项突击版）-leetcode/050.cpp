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
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        vector<int> debug;
        helper(root, 0, 0, targetSum, result, debug);
        return result/4;
    }

    void helper(TreeNode* node, int pathSum, int pathLength, int targetSum, int &result, vector<int> debug) {

        if(pathSum == targetSum && pathLength > 0) {
            result += 1;

            for(auto t:debug) {
                cout << t << " ";
            }
            cout << endl;
            return;
        }

        if(node == nullptr) {
            return;
        }

        // 这个节点是中间路径中的一个
        pathSum += node->val;
        debug.push_back(node->val);
        helper(node->left, pathSum, pathLength + 1,targetSum, result, debug);
        helper(node->right, pathSum, pathLength + 1,targetSum, result, debug);
        pathSum -= node->val;

        // 从这个节点 开始
        pathSum = node->val;
        debug.clear();
        debug.push_back(node->val);
        helper(node->left, pathSum, 1, targetSum, result, debug);
        helper(node->right, pathSum, 1, targetSum, result, debug);
    }
};

int main() {
    Solution s;

    TreeNode *l0 = new TreeNode(10);

    TreeNode *l1_0 = new TreeNode(5);
    TreeNode *l1_1 = new TreeNode(-3);

    TreeNode *l2_0 = new TreeNode(3);
    TreeNode *l2_1 = new TreeNode(2);
    TreeNode *l2_3 = new TreeNode(11);

    TreeNode *l3_0 = new TreeNode(3);
    TreeNode *l3_1 = new TreeNode(-2);
    TreeNode *l3_3 = new TreeNode(1);


    l0->left = l1_0;
    l0->right = l1_1;

    l1_0->left = l2_0;
    l1_0->right = l2_1;
    l1_1->left = nullptr;
    l1_1->right = l2_3;

    l2_0->left = l3_0;
    l2_0->right = l3_1;
    l2_1->left = nullptr;
    l2_1->right = l3_3;

    cout << s.pathSum(l0, 8) << endl;

    return 0;
}

int main1() {
    Solution s;

    TreeNode *l0 = new TreeNode(0);

    TreeNode *l1_0 = new TreeNode(1);
    TreeNode *l1_1 = new TreeNode(1);


    l0->left = l1_0;
    l0->right = l1_1;

    cout << s.pathSum(l0, 0) << endl;

    return 0;
}
