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
    ListNode *detectCycle(ListNode *head) {

        if(head == nullptr) {
            return nullptr;
        }

        map<ListNode*, int> indexMap;

        int index = 0;
        while(head != nullptr) {
            auto iter = indexMap.find(head);
            if(iter != indexMap.end()) {
                return iter->first;
            }
            indexMap[head] = index;
            head = head->next;
            index += 1;
        }
        

        return nullptr;
        
    }
};


class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == nullptr) {
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr) {
            slow = slow->next;

            fast = fast->next;
            if(fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;

            if(slow == fast) {
                return slow;
            }
        }

        return nullptr;
        
    }
};


int main() {
    Solution2 s;

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
