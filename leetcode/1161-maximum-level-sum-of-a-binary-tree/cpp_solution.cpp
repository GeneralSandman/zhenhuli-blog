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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        map<int,int> hashTable;
        int maxVal = INT_MIN;
        int minLevel = 1;
        helper(root, 1, hashTable);

        for(auto i = hashTable.begin(); i != hashTable.end(); i++) {
            if (i->second > maxVal) {
                maxVal = i->second;
                minLevel = i->first;
            }
        }

        return minLevel;
    }

    void helper(TreeNode* root, int level, map<int,int> &hashTable) {
        if (root == nullptr) {
            return;
        }

        hashTable[level] += root->val;
        helper(root->left, level + 1, hashTable);
        helper(root->right, level + 1, hashTable);
    }
};

int main() {
    Solution s;

    TreeNode* n31 = new TreeNode(7);
    TreeNode* n32 = new TreeNode(-8);

    TreeNode* n21 = new TreeNode(7, n31, n32);
    TreeNode* n22 = new TreeNode(0);

    TreeNode* n11 = new TreeNode(2, n21, n22);

    cout << s.maxLevelSum(n11) << endl;

    return 0;
}
