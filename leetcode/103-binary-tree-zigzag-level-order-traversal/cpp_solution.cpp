#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == nullptr) {
            return result;
        }

        queue<TreeNode*> queueTree;

        queueTree.push(root);

        bool leftToRight = true;
        while(queueTree.size()) {
            int size = queueTree.size();
            vector<int> level(size);
            for(int i=0;i<size;i+=1) {
                
                int index = leftToRight ? i : size - i - 1;

                TreeNode* front = queueTree.front();
                queueTree.pop();
                level[index] = front->val;

                if(front->left) {
                    queueTree.push(front->left);
                }

                if(front->right) {
                    queueTree.push(front->right);
                }

            }

            leftToRight = !leftToRight;

            result.push_back(level);
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
