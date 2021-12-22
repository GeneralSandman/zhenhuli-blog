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
    bool findTarget(TreeNode* root, int k) {
        map<int, bool> valueHashTable;
        return helperDfs(root, valueHashTable, k);
    }

    bool helperDfs(TreeNode* node, map<int, bool> &valueHashTable, int target) {
        if(node == nullptr) {
            return false;
        }

        if(valueHashTable.find(target - node->val) != valueHashTable.end()) {
            return true;
        }
        valueHashTable[node->val] = true;
        if (helperDfs(node->left, valueHashTable, target)) {
            return true;
        }
        if (helperDfs(node->right, valueHashTable, target)) {
            return true;
        }
        return false;
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

    cout << s.findTarget(l0, 6) << endl;


    return 0;
}
