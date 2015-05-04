/**
 * LeetCode 203 Remove Linked List Elements.
 * https://leetcode.com/problems/remove-linked-list-elements/
 */

#include "..\singlyLinkedList.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;

        ListNode pseHead =  ListNode(0);
        pseHead.next = head;
        ListNode *p = head, *pre = &pseHead;

        while(p) {
            if (p->val == val) {
                ListNode *q = p;
                p = p->next;
                pre->next = p;
                free(q);
            } else {
                pre = p;
                p = p->next;
            }
        }

        return pseHead.next;
    }
};


int main()
{
    ListNode *p = NULL;
    int a[] = {1, 2, 6, 3, 4, 6, 5};
    for (int i = 0; i < 7; ++i) {
        insertInPost(&p, a[i]);
    }

    Solution ans;
    ListNode *res = ans.removeElements(p, 5);
    traverse(&res);

    return 0;
}

