#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) {
            return head;
        }

        Node* pre = nullptr;
        
        stack<Node*> accessPath;
        accessPath.push(head);
        while(!accessPath.empty()) {

            auto top = accessPath.top();
            cout << top->val << endl;
            accessPath.pop();

            if(top->next != nullptr) {
                accessPath.push(top->next);
            }

            if(top->child != nullptr) {
                accessPath.push(top->child);
            }

        }

        return head;

    }
};

int main() {
    Solution s;

    Node* l0_0 = new Node(0);
    Node* l0_1 = new Node(1);
    Node* l0_2 = new Node(2);
    Node* l0_3 = new Node(3);
    Node* l0_4 = new Node(4);

    Node* l1_0 = new Node(5);
    Node* l1_1 = new Node(6);

    Node* l2_0 = new Node(7);

    l0_0->next=l0_1;
    l0_1->next=l0_2;
    l0_2->next=l0_3;
    l0_3->next=l0_4;

    l1_0->next = l1_1;


    l0_1->child = l1_0;
    l1_0->child = l2_0;

    cout << s.flatten(l0_0) << endl;


    return 0;
}
