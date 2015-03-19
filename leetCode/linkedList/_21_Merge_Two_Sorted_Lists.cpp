/**
 * LeetCode 21 Merge Two Sorted Lists.
 * https://leetcode.com/problems/merge-two-sorted-lists/
 */

#include "singlyLinkedList.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2){
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};


int main()
{
    ListNode *List1 = NULL;
    ListNode *List2 = NULL;
    const int N = 5;
    int arry[N] = {1, 1, 2, 3, 3};
    for (int i=0; i < N; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    const int N2 = 4;
    int arry2[N2] = {0, 0, 1, 1};
    for (int i=0; i < N2; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List2, arry2[i])){
            cout << "Error!" << endl;
            return 1;
        }

    //traverse(&List1);
    //traverse(&List2);

    Solution A;
    ListNode *ans = A.mergeTwoLists(List1, List2);
    traverse(&ans);

    return 0;
}
