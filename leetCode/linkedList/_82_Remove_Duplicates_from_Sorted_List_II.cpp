/**
 * LeetCode 82 Remove Duplicates from Sorted List II.
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 */

#include "..\singlyLinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return head;

        ListNode pseHead(0);
        pseHead.next = head;
        ListNode* pre = &pseHead, *p = head;

        while (p && p->next) {
            if (p->val == p->next->val) {
                int duplicateVal = p->val;
                while (p && p->val == duplicateVal)
                    p = p->next;
                pre->next = p;
            } else {
                pre = p;
                p = p->next;
            }
        }

        return pseHead.next;
    }

    // https://leetcode.com/discuss/21524/is-this-the-best-c-solution
    ListNode* deleteDuplicates2(ListNode* head) {
        // 解释未必正确，先记下。
        if (!head || !(head->next)) return head;

        // runner是指向存放head指针地址的指针。
        ListNode** runner = &head;
        while (*runner) {
            if ((*runner)->next && (*runner)->val == (*runner)->next->val) {
                ListNode *temp = (*runner)->next;
                while (temp && temp->val == (*runner)->val)
                    temp = temp->next;

                *runner = temp;
            } else {
                // runner为了下一个指针的地址。
                runner = &((*runner)->next);
            }
        }

        return head;
    }
};


int main()
{
    ListNode *p = NULL;
    int a[] = {1, 2, 2};
    for (int i = 0; i < 3; ++i) {
        insertInPost(&p, a[i]);
    }

    Solution ans;
    ListNode* res = ans.deleteDuplicates2(p);
    traverse(&res);

    return 0;
}
