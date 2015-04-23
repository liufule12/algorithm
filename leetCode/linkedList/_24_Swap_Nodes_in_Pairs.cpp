/**
 * LeetCode 24 Linked List Cycle II.
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 */

#include "..\singlyLinkedList.h"


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode *tail = head;
        ListNode *p = head;
        ListNode *last;
        int lenList = 0, step = 0;

        while(tail->next){
            tail = tail->next;
            ++lenList;
        }
        step = (lenList == 1) ? 1 : lenList + 1;

        for (int i = 0; i < step; ++i){
            p = head;
            head = head->next;
            tail->next = p;

            if (i % 2 == 0){
                p->next = NULL;
                last = p;
            }else{
                p->next = last;
                tail = last;
            }
        }

        return head;
    }
/*
    ListNode *swapPairs2(ListNode *head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode dumpyHead(0);
        ListNode start(-1);
        start.next = head;
        dumpyHead.next = head->next;

        ListNode *cur = head;

        while(cur && cur->next){
            cout << "Cur->val: " << cur->val << endl;
            start.next = cur->next;
            cur->next = (start.next)->next;
            start.next = cur;

            cur = cur->next;
            start = *(start.next);

            traverse(&dumpyHead.next);
            cout << endl;
        }
        return dumpyHead.next;
    }*/
};


int main()
{
    ListNode *List1 = NULL;
    const int N = 5;
    int arry[N] = {1, 2, 3, 4, 5};
    for (int i = 0; i < N; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }

    //traverse(&List1);

    Solution A;
    ListNode *ans = A.swapPairs(List1);
    traverse(&ans);

    return 0;
}
