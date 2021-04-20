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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }

    ListNode* helper(ListNode* l1, ListNode* l2, int val) {
        if (l1 == nullptr && l2 == nullptr && val == 0) {
            return nullptr;
        }

        int current = val;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        if (l1 != nullptr) {
            current += l1->val;
            next1 = l1->next;
        }

        if (l2 != nullptr) {
            current += l2->val;
            next2 = l2->next;
        }

        ListNode* newNode = new ListNode(current%10);

        newNode->next = helper(next1, next2, current/10);
        return newNode;
    }
};

int main_() {
    Solution s;

    ListNode *l13 = new ListNode(3);
    ListNode *l12 = new ListNode(4, l13);
    ListNode *l11 = new ListNode(2, l12);

    ListNode *l23 = new ListNode(4);
    ListNode *l22 = new ListNode(6, l23);
    ListNode *l21 = new ListNode(5, l22);

    ListNode *result = s.addTwoNumbers(l11,l21);
    while(result != nullptr) {
        cout << "listNode:" << result->val << endl;
        result = result->next;
    }

    return 0;
}

int main() {
    Solution s;

    ListNode *l17 = new ListNode(9);
    ListNode *l16 = new ListNode(9, l17);
    ListNode *l15 = new ListNode(9, l16);
    ListNode *l14 = new ListNode(9, l15);
    ListNode *l13 = new ListNode(9, l14);
    ListNode *l12 = new ListNode(9, l13);
    ListNode *l11 = new ListNode(9, l12);

    ListNode *l24 = new ListNode(9);
    ListNode *l23 = new ListNode(9, l24);
    ListNode *l22 = new ListNode(9, l23);
    ListNode *l21 = new ListNode(9, l22);

    ListNode *result = s.addTwoNumbers(l11,l21);
    while(result != nullptr) {
        cout << "listNode:" << result->val << endl;
        result = result->next;
    }

    return 0;
}