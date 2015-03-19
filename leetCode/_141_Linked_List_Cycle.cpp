/**
 * LeetCode 141 Linked List Cycle.
 * https://leetcode.com/problems/linked-list-cycle/
 */

#include "singlyLinkedList.h"


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ��������ָ�룬��ָ��ÿ������������ָ��ÿ����һ����
        // ������ָ����ǰ����ָ���ں������൱�ڿ�ָ��ÿ������ָ�뿿��һ����
        // ��ָ��Ϊ�գ����޻�������ָ�������ָ�룬���л���
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)   return true;
        }

        return false;
    }
};


int main()
{
    ListNode *List1 = NULL;
    const int N = 5;
    int arry[N] = {1};
    for (int i = 0; i < N; ++i)
        // ������β�����룬����
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }

    ListNode *tail = List1;

    while(tail->next)
        tail = tail->next;
    tail->next = tail;

    //traverse(&List1);

    Solution A;
    if(A.hasCycle(List1))
        cout << "Has cycle!" << endl;
    else
        cout << "Has not cycle!" << endl;

    return 0;
}
