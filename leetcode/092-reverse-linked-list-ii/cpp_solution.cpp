#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <climits>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }

        stack<ListNode*> s;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        int index = 0;

        ListNode* result = new ListNode(INT_MIN, head);
        ListNode* node = result;


        while(node != nullptr) {
            if (left > index) {
                a = node;
            } else if (left <= index && index <= right) {
                s.push(node);
            } else {
                b = node;
                break;
            }
            index += 1;
            node = node->next;
        }

        while(!s.empty()) {
            ListNode* tmp = s.top();
            s.pop();
            a->next = tmp;
            a = a->next;
        }

        a->next = b;
        return result->next;
    }
};

int main() {
    Solution s;

    ListNode *n5 = new ListNode(5);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    ListNode *result = s.reverseBetween(n1, 3, 3);
    
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << "\n";
    return 0;
}
