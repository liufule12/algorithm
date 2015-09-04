/**
 * LeetCode 86 Partition List.
 * https://leetcode.com/problems/partition-list/
 */

#include "..\singlyLinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode pseHead1(0), pseHead2(0);
        ListNode *p1 = &pseHead1, *p2 = &pseHead2, *p = head;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p;
            }
            else {
                p2->next = p;
                p2 = p;
            }
            p = p->next;
        }
        p1->next = pseHead2.next;
        p2->next = NULL;

        return pseHead1.next;
    }
};


int main()
{
    ListNode *p = NULL;
    int a[] = {1, 4, 5, 3, 2, 1, 5, 2};
    for (int i = 0; i < 8; ++i) {
        insertInPost(&p, a[i]);
    }

    Solution ans;
    ListNode* res = ans.partition(p, 3);
    traverse(&res);

    return 0;
}
