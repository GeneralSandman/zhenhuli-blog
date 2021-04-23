#include <iostream>
#include <vector>
#include <map>

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
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;
        ListNode* newHead = nullptr;

        while(head) {
            newHead = head;
            head = head->next;
            newHead->next = pre;
            pre = newHead;
        }

        return newHead;
    }

    ListNode* reverseList2(ListNode* head) {

        if(head == nullptr) {
            return nullptr;
        }


    }

    void helper(ListNode* cur, ListNode* next) {

        helper(cur, next);
    }
};

int main() {
    Solution s;

    ListNode* n4 = new ListNode(4);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    ListNode* n0 = new ListNode(0, n1);

    ListNode * tmp = n0;
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }


    tmp = s.reverseList(n0);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    tmp = s.reverseList2(n0);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    return 0;
}
