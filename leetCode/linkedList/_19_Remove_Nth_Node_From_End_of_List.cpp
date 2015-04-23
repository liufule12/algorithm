/**
 * LeetCode 19 Remove Nth Node From End of List.
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

#include "..\singlyLinkedList.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // ��������ָ�롣
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i=0; i < n; i++)
            fast = fast->next;

        if (fast != NULL){
            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            fast = slow->next;
            slow->next = slow->next->next;
            free(fast);
        }
        else{
            head = head->next;
            free(slow);
        }

        return head;
    }
};


int main()
{
    struct ListNode *List = NULL;
    int arry[2] = {1, 2};
    for (int i=0; i < 2; ++i)
        // ������ͷ�����룬����
        //if(!insertInFront(&List, arry[i])){
        //    cout << "Error!" << endl;
        //    return 1;
        //}
        // ������β�����룬����
        if(!insertInPost(&List, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }
    //traverse(&List);

    int n = 2;
    Solution A;
    ListNode *ans = A.removeNthFromEnd(List, n);
    traverse(&ans);

    return 0;
}
