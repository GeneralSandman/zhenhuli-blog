#include <iostream>
#include <vector>
#include <map>
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next != nullptr) {
            curr->next = pre;

            pre = curr;
            curr = next;
            next = next->next;
        }

        curr->next = pre;
        
        return curr;
    }
};


class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* result;
        helper(head, result);
        return result;
    }

    ListNode* helper(ListNode* head, ListNode* &result) {
        // if(head == nullptr) {
        //     return nullptr;
        // }
        if(head->next == nullptr) {
            result = head;
            return head;
        }


        ListNode* tail = helper(head->next, result);
        tail->next = head;
        head->next = nullptr;
        return head;
    }
};


class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* result = nullptr;

        stack<ListNode*> accessPath;
        while(head != nullptr) {
            accessPath.push(head);
            head = head->next;
        }

        result = accessPath.top();
        accessPath.pop();

        ListNode* pre = result;
        while(!accessPath.empty()) {
            ListNode* tmp = accessPath.top();
            accessPath.pop();
            tmp->next = nullptr;
            pre->next = tmp;
            pre = tmp;
        }

        return result;
    }
};


// 有三种解法
// 循环
// 递归
// stack
int main() {
    Solution3 s;

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
    // l5->next = l1;

    auto res = s.reverseList(l0);
    while(res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
