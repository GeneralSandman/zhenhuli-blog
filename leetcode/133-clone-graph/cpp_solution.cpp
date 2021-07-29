#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        if(hashTable.find(node) == hashTable.end()) {
            Node* newNode = new Node(node->val);
            hashTable[node] = newNode;
            for(auto neighbor : node->neighbors) {
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return hashTable[node];
    }
private:
    map<Node*, Node*> hashTable;
};

int main() {
    Solution s;

    return 0;
}
