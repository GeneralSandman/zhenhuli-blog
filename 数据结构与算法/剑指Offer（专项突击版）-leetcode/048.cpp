#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;

        if(root == nullptr) {
            return "#,";
        }

        result = to_string(root->val);
        result += ",";
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) {
            return nullptr;
        }
        queue<string> result = helper1(data);
        return helper2(result);
    }

    queue<string> helper1(string data) {
        queue<string> result;

        string tmp;
        for(auto t:data) {
            if(t==',') {
                result.push(tmp);
                tmp = "";
            } else {
                tmp += t;
            }
        }

        if(tmp!="") {
            result.push(tmp);
        }
        return result;
    }

    TreeNode* helper2(queue<string> &dfsPath) {
        if(dfsPath.empty()) {
            return nullptr;
        }

        string value = dfsPath.front();
        dfsPath.pop();

        if(value == "#") {
            return nullptr;
        }

        TreeNode *node = new TreeNode(atoi(value.c_str()));
        node->left = helper2(dfsPath);
        node->right = helper2(dfsPath);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    TreeNode *l0 = new TreeNode(11);

    TreeNode *l1_0 = new TreeNode(3);
    TreeNode *l1_1 = new TreeNode(2);

    TreeNode *l2_0 = new TreeNode(5);
    TreeNode *l2_1 = new TreeNode(3);
    TreeNode *l2_2 = new TreeNode(9);

    TreeNode *l3_0 = new TreeNode(7);


    l0->left = l1_0;
    // l0->right = l1_1;

    l1_0->left = l2_0;
    // l1_0->right = l2_1;
    // l1_1->left = nullptr;
    // l1_1->right = l2_2;

    // l2_2->left = l3_0;

    Codec s;
    auto tmp = s.serialize(l0);
    cout << tmp << endl;
    s.deserialize(tmp);

    return 0;
}
