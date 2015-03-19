/**
 * LeetCode 160 Intersection of Two Linked Lists.
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

#include "singlyLinkedList.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        // 首先求得两个单链表之差，较短的链表移动差的步数。
        if (!headA || !headB )   return NULL;

        ListNode *l1 = headA;
        ListNode *l2 = headB;
        int lenA = 0, lenB = 0;

        while(l1){
            ++lenA;
            l1 = l1->next;
        }
        while(l2){
            ++lenB;
            l2 = l2->next;
        }

        int step = lenA - lenB;
        if (step > 0)
            for (int i = 0; i < step; ++i)
                headA = headA->next;
        else
            for (int i = 0; i > step; --i)
                headB = headB->next;

        while(headA){
            if (headA == headB)
                return headA;
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }

        return NULL;
    }
};


int main()
{
    ListNode *List1 = NULL;
    ListNode *List2 = NULL;
    ListNode *List3 = NULL;
    const int N = 5;
    int arry[N] = {1, 2, 3, 4, 5};
    for (int i=0; i < N; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    const int N2 = 4;
    int arry2[N2] = {1, 2, 3, 3};
    for (int i=0; i < N2; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List2, arry2[i])){
            cout << "Error!" << endl;
            return 1;
        }
    const int N3 = 4;
    int arry3[N3] = {9, 1, 2, 3};
    for (int i=0; i < N3; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List3, arry3[i])){
            cout << "Error!" << endl;
            return 1;
        }

    ListNode *p1 = List1;
    ListNode *p2 = List2;
    while(p1->next)
        p1 = p1->next;
    while(p2->next)
        p2 = p2->next;
    p1->next = List3;
    p2->next = List3;

    //traverse(&List1);
    //traverse(&List2);
    //traverse(&List3);

    Solution A;
    ListNode *ans = A.getIntersectionNode(List1, List2);
    traverse(&ans);

    return 0;
}
