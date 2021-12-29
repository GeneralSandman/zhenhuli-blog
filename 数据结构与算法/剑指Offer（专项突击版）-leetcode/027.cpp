#include <iostream>
#include <vector>
#include <map>
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {
            return false;
        }
        if(head->next == nullptr) {
            return true;
        }
        bool evenNum = false;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* first = head;
        ListNode* second = nullptr;

        if(fast->next != nullptr) {
            // 偶数
            second = slow->next;
        } else {
            // 奇数
            second = slow;
        }


        string firstStr, secondStr;
        while(first != slow->next) {
            firstStr += to_string(first->val);
            first = first->next;
        }

        while(second != nullptr) {
            secondStr = to_string(second->val) + secondStr;
            second = second->next;
        }

        // cout << firstStr << endl;
        // cout << secondStr << endl;

        return firstStr == secondStr;
    }
};


int main() {
    Solution s;

    ListNode *l0 = new ListNode(1);
    ListNode *l1 = new ListNode(2);
    // ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(1);

    l0->next = l1;
    l1->next = l3;
    // l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    auto res = s.isPalindrome(l0);

    return 0;
}
