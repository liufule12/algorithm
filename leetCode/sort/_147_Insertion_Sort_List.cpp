/**
 * LeetCode 147 Insertion Sort List.
 * https://leetcode.com/problems/insertion-sort-list/
 */

#include "..\singlyLinkedList.h"


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode numpy(0);
        numpy.next = head;
        ListNode *p = head->next;
        ListNode *tail = head;
        ListNode *pre, *preNext;
        // βָ��next��һ��Ҫ��ΪNULL���������ֻ���
        tail->next = NULL;

        while (p){
            if (tail->val > p->val){
                // ���������Ԫ�ر�β������Ԫ��С�����ͷ���Ƚϲ��롣
                pre = &numpy;
                while(pre->next && p->val > pre->next->val)
                    pre = pre->next;
                preNext = pre->next;
                pre->next = p;
                p = p->next;
                pre->next->next = preNext;
            }else{
                // ���������Ԫ�ر�β������Ԫ�ػ��󣬾�ֱ�Ӳ���β����
                tail->next = p;
                p = p->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        return numpy.next;
    }
};


int main()
{
    ListNode *List1 = NULL;
    const int N = 8;
    int arry[N] = {5, 3, 6, 2, 1, 8, 7, 4};
    for (int i = 0; i < N; ++i)
        // ������β�����룬����
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    //traverse(&List1);

    Solution A;
    ListNode *ans = A.insertionSortList(List1);
    traverse(&ans);

    return 0;
}
