#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BSTIterator {

private:
    TreeNode *root;

    stack<TreeNode*> accessQueue;

    void buildAccessQueue(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        buildAccessQueue(root->right);
        accessQueue.push(root);
        buildAccessQueue(root->left);
    }

public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        buildAccessQueue(root);
    }
    
    int next() {
        TreeNode *node = accessQueue.top();
        accessQueue.pop();
        return node->val;
    }
    
    bool hasNext() {
        return !accessQueue.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    Solution s;

    return 0;
}
