/**
 * LeetCode 206 Reverse a singly linked list..
 * https://leetcode.com/problems/reverse-linked-list/
 */

#include "..\singlyLinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)  return NULL;
        ListNode pseHead(0);
        ListNode* p = &pseHead, *q = head, *nextNode = head->next;

        while(nextNode) {
            q->next = p;
            p = q;
            q = nextNode;
            nextNode = nextNode->next;
        }
        q->next = p;
        head->next = NULL;

        return q;
    }

    // https://leetcode.com/discuss/43994/8ms-c-iterative-and-recursive-solutions-with-explanations
    ListNode* reverseList2(ListNode* head) {
        ListNode *pre = NULL;
        while(head) {
            ListNode *nextNode = head->next;
            head->next = pre;
            pre = head;
            head = nextNode;
        }

        return pre;
    }
};


int main()
{
    ListNode *p = NULL;
    int a[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; ++i) {
        insertInPost(&p, a[i]);
    }

    Solution ans;
    //ListNode *res = ans.reverseList(p);
    ListNode *res = ans.reverseList2(p);
    traverse(&res);

    return 0;
}
