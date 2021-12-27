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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if(root == nullptr) {
            return result;
        }

        helper(root, result, 0);
        return result;
    }

    void helper(TreeNode* node, vector<int>& result, int level) {
        if(node == nullptr) {
            return;
        }
        if(result.size()<=level) {
            result.push_back(node->val);
        }
        helper(node->right, result, level+1);
        helper(node->left, result, level+1);
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

    vector<int> result = s.rightSideView(l0);
    for(auto t: result) {
        cout << t << endl;
    }



    return 0;
}
