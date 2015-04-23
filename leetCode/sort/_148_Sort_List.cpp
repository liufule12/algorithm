/**
 * LeetCode 149 Sort List.
 * https://leetcode.com/problems/sort-list/
 * Merge Sort, O(NlogN).
 */

#include "..\singlyLinkedList.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *p = head, *q, *tail;
        ListNode dummy(0);
        dummy.next = p;
        int length = 0, step = 1;
        while(p){
            ++length;
            p = p->next;
        }

        for(; step < length; step *= 2){
            // Do logN sub merge sort, step means pointer's move steps in every sub merge.
            // For example, if the merge width is 4, then step is 4/2=2.
            p = dummy.next;
            q = dummy.next;
            tail = &dummy;

            int round = length / (step * 2) + 1;
            for (int i = 0; i < round; ++i){
                // Sub merge, there are length / (step * 2) + 1 in every sub merge.
                // In every round, q move to the right position.
                for (int i = 0; i < step && q; ++i)
                    q = q->next;

                // Do merge.
                int step1 = 0, step2 = 0;
                while (step1 < step && step2 < step && p && q){
                    if (p->val <= q->val){
                        tail->next = p;
                        p = p->next;
                        ++step1;
                    }else{
                        tail->next = q;
                        q = q->next;
                        ++step2;
                    }
                    tail = tail->next;
                    tail->next = NULL;
                }
                for (; step1 < step && p; ++step1){
                    tail->next = p;
                    p = p->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
                for (; step2 < step && q; ++step2){
                    tail->next = q;
                    q = q->next;
                    tail = tail->next;
                    tail->next = NULL;
                }

                // p move to right position for next round.
                p = q;
            }
            tail->next = p ? p : q;
        }

        return dummy.next;
    }
};


int main()
{
    ListNode *List1 = NULL;
    const int N = 5;
    int arry[N] = {5, 1, 3, 2, 4};
    for (int i=0; i < N; ++i)
        // 单链表尾部插入，正序。
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    //traverse(&List1);

    Solution A;
    ListNode *ans = A.sortList(List1);
    traverse(&ans);

    return 0;
}
