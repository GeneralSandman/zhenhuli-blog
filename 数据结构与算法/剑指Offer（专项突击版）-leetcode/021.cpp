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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 使用双指针
        // 快指针先走
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *virtualNode = new ListNode(0);
        virtualNode->next = head;

        ListNode* fast = virtualNode;
        ListNode* slow = virtualNode;

        while(n>=0) {
            fast = fast->next;
            n-=1;
        }

        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;


        auto result = virtualNode->next;
        delete virtualNode;
        return result;
    }
};



int main() {
    Solution s;

    ListNode *l0 = new ListNode(0);
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);

    l0->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    auto res = s.removeNthFromEnd(l0, 5);
    while(res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
