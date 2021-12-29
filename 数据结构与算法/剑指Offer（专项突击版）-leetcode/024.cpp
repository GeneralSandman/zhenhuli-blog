#include <iostream>
#include <vector>
#include <map>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *tmpA = headA;
        ListNode *tmpB = headB;

        while(tmpA != nullptr && tmpB != nullptr) {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        ListNode *longerList = headA;
        ListNode *shortList = headB;

        int distanceDiff = 0;
        while(tmpA != nullptr) {
            longerList = headA;
            shortList = headB;
            distanceDiff += 1;
            tmpA = tmpA->next;
        }

        while(tmpB != nullptr) {
            longerList = headB;
            shortList = headA;
            distanceDiff += 1;
            tmpB = tmpB->next;
        }

        while(distanceDiff--) {
            longerList = longerList->next;
        }

        while(longerList != nullptr && shortList != nullptr) {
            if(longerList == shortList) {
                return longerList;
            }

            longerList = longerList->next;
            shortList = shortList->next;
        }

        return nullptr;
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
    l5->next = l1;

    auto res = s.detectCycle(l0);
    cout << res->val << endl;

    return 0;
}
