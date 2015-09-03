/**
 * LeetCode 234 Palindrome Linked List.
 * https://leetcode.com/problems/palindrome-linked-list/
 */

#include "..\singlyLinkedList.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)  return true;

        // Find the length of LinkList.
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            ++length;
            tail = tail->next;
        }

        // Go to the middle point.
        int step = (length + 1) / 2;
        ListNode *p = head;
        for (int i = 0; i < step; ++i)
            p = p->next;

        // Reverse LinkList after p.
        ListNode *pre = NULL;
        while (p) {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        // Determine.
        do {
            if (head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
            --step;
        } while (step > 0 && tail);

        return true;
    }

    bool isPalindrome2(ListNode* head) {
        if (!head || !(head->next))  return true;

        // 使用快慢指针能快速走到中间位置。
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow->next);

        while (slow) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }

    ListNode *reverseList(ListNode *p) {
        // Reverse LinkList.
        ListNode *pre = NULL;
        while (p) {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        return pre;
    }
};


int main()
{
    ListNode *p = NULL;
    int a[] = {1, 2, 1, 1};
    for (int i = 0; i < 4; ++i) {
        insertInPost(&p, a[i]);
    }

    Solution ans;
    bool res = ans.isPalindrome2(p);
    if (res)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
