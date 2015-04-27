/**
 * LeetCode 61 Rotate List.
 * https://leetcode.com/problems/rotate-list/
 */

#include "..\singlyLinkedList.h"


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;

        int lenList = 0;
        ListNode *fast = head, *slow = head;
        while (fast) {
            ++lenList;
            fast = fast->next;
        }

        // Set and move fast and slow point.
        if (k >= lenList)
            k %= lenList;
        fast = head;
        for (int i = 0; i < k; ++i)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Rotate.
        fast->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
    }
};


int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    ListNode *head = NULL;
    for (int i = 0; i < 5; ++i)
        insertInPost(&head, a[i]);

    Solution ans;
    ListNode *res;
    res = ans.rotateRight(head, 2);
    traverse(&res);

    return 0;
}

