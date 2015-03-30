/**
 * LeetCode 2 Add Two Numbers.
 * https://leetcode.com/problems/add-two-numbers/
 */


#include "singlyLinkedList.h"


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2){
            // ��������ע�͵Ĵ����Ǵ���ģ���ֻ����ѭ����ÿ�ζ���һ���ֲ������������ջ�У������node->next = &node�����������Ի������Һ���ִ�������Щ�洢��Ԫ�ᱻϵͳ�Զ��ͷš�
            // ������ȷ�ķ�������new���ڶ��з������ڴ棬�������ڴ�ķ�����ͷű����ɳ���Ա�ֶ��ͷš�
            // ListNode node(l1->val + l2->val);
            // tail->next = &node;
            tail->next = new ListNode(l1->val + l2->val);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        tail->next = l1 ? l1 : l2;

        int carry = 0;
        tail = dummy.next;
        ListNode *tailPre;
        while(tail){
            tailPre = tail;
            int tempRes = tail->val + carry;
            if (tempRes < 10)
                carry = 0;
            else
                carry = 1;

            tail->val = tempRes % 10;
            tail = tail->next;
        }
        if (1 == carry)
            tailPre->next = new ListNode(1);

        return dummy.next;
    }

    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
}
};


int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    const int N1 = 3;
    const int N2 = 3;
    int A1[N1] = {7, 0, 3};
    int A2[N2] = {3, 9, 7};

    for (int i = 0; i < N1; ++i)
        insertInPost(&l1, A1[i]);
    for (int i = 0; i < N2; ++i)
        insertInPost(&l2, A2[i]);

    Solution ans;
    ListNode *ansPoint = ans.addTwoNumbers(l1, l2);
    traverse(&ansPoint);

    return 0;
}
