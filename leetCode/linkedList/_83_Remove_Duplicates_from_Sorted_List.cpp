/**
 * LeetCode 83 Remove Duplicates from Sorted List.
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

#include "..\singlyLinkedList.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head) {
        // 使用两个指针遍历，删除重复。23ms。
        if (head == NULL)   return head;

        ListNode *fast = head;
        ListNode *slow = head;

        fast = fast->next;
        while(fast != NULL){
            if (fast->val == slow->val){
                if (fast->next != NULL){
                    slow->next = fast->next;
                    free(fast);
                    fast = slow->next;
                }else{
                    slow->next = NULL;
                    free(fast);
                    return head;
                }
            }else{
                fast = fast->next;
                slow = slow->next;
            }
        }

        return head;
    }

    ListNode *removeNthFromEnd2(ListNode *head) {
        // 由于单链表本身有序，所以只需要存储1个指针，1个数字，即可去除重复，减少了指针的操作。20ms。
        if (head == NULL)   return head;

        ListNode *p = head;
        ListNode *q;
        int curNum = head->val;

        while(p->next != NULL){
            if (p->next->val == curNum){
                q = p->next;
                p->next = p->next->next;
                free(q);
            }else{
                p = p->next;
                curNum = p->val;
            }
        }

        return head;
    }
};


int main()
{
    struct ListNode *List = NULL;
    const int N = 5;
    int arry[N] = {1, 1, 2, 3, 3};
    for (int i=0; i < N; ++i)
        if(!insertInPost(&List, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    //traverse(&List);

    Solution A;
    ListNode *ans = A.removeNthFromEnd2(List);
    traverse(&ans);

    return 0;
}
