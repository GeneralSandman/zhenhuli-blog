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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> hashTable;
        int maxFrequent = INT_MIN;
        helper(root, hashTable, maxFrequent);

        vector<int> result;
        for(auto i = hashTable.begin(); i != hashTable.end(); i++) {
            if (i->second == maxFrequent) {
                result.push_back(i->first);
            }
        }

        return result;
    }

    int helper(TreeNode* root, map<int,int> &hashTable, int &maxFrequent) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = root->val;
        sum += helper(root->left, hashTable, maxFrequent);
        sum += helper(root->right, hashTable, maxFrequent);
        hashTable[sum] += 1;
        maxFrequent = max(maxFrequent, hashTable[sum]);
        return sum;
    }
};

int main() {
    Solution s;

    return 0;
}
