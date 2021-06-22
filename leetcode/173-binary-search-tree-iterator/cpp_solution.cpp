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
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        TreeNode* result = s.top();
        s.pop();

        helper(result->right);

        return result->val;
    }
    
    bool hasNext() {
        if (s.empty()) {
            return false;
        }
        return true;
    }

private:
    stack<TreeNode*> s;

    void helper(TreeNode* root) {
        TreeNode* node = root;
        
        while(node) {
            s.push(node);
            node = node->left;
        }
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
