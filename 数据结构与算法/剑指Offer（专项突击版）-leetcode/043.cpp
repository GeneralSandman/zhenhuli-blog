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

class CBTInserter {

private:
    TreeNode *root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    // 广度优先搜索，找到第一个 左边或者右边 是空的节点
    int insert(int v) {
        TreeNode *newNode = new TreeNode(v);

        queue<TreeNode*> bfsAccess;
        bfsAccess.push(this->root);

        TreeNode *parent = bfsAccess.front();
        bfsAccess.pop();
        while(parent->left != nullptr && parent->right != nullptr) {
            bfsAccess.push(parent->left);
            bfsAccess.push(parent->right);

            parent = bfsAccess.front();
            bfsAccess.pop();
        }

        if(parent->left == nullptr) {
            parent->left = newNode;
        } else if(parent->right == nullptr) {
            parent->right = newNode;
        }
        return parent->val;

    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main() {
    Solution s;

    return 0;
}
