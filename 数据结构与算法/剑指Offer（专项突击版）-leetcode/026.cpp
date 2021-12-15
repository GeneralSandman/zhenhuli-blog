#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {

        queue<ListNode*> q;
        stack<ListNode*> s;

        int nodeNum = 0;

        while(head!=nullptr) {
            q.push(head);
            s.push(head);
            head = head->next;
            nodeNum += 1;
        }

        int tmp = 0;
        ListNode* result = new ListNode();

        ListNode* preNode = result;

        while(tmp!=nodeNum) {
            ListNode* node;
            if(tmp %2 == 0) {
                node = q.front();
                q.pop();
            } else {
                node = s.top();
                s.pop();
            }

            cout << node->val << endl;

            preNode->next = node;
            preNode = node;
            tmp += 1;
        }

        head = result->next;

    }
};

int main() {
    Solution s;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;


    s.reorderList(node1);

    while(node1!=nullptr){
        cout << node1->val << endl;
        node1 = node1->next;
    }

    return 0;
}
