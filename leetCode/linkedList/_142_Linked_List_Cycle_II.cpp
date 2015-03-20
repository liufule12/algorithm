/**
 * LeetCode 142 Linked List Cycle II.
 * https://leetcode.com/problems/linked-list-cycle-ii/
 */

#include "singlyLinkedList.h"


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ��������ָ�룬��ָ��ÿ������������ָ��ÿ����һ����
        // ������ָ����ǰ����ָ���ں������൱�ڿ�ָ��ÿ������ָ�뿿��һ����
        // ��ָ��Ϊ�գ����޻�������ָ�������ָ�룬���л���
        // ����http://blog.csdn.net/hf81970/article/details/14169655���ӱ�ͷ����ͷ�ľ��������ָ�뽻�㵽��ͷ�ľ�����ȡ�
        // ����ֻ���ͷָ��Ϳ���ָ�����ཻ��ͬʱ�ߣ���ͷָ�������ָ���ཻ�㼴Ϊ��ͷ��
        ListNode *fast = head;
        ListNode *slow = head;
        bool hasCycle = false;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                hasCycle = true;
                break;
            }
        }

        if (hasCycle){
            while(true){
                if (fast == head)
                    return head;
                fast = fast->next;
                head = head->next;
            }
        }
        return NULL;
    }
};


int main()
{
    ListNode *List1 = NULL;
    const int N = 5;
    int arry[N] = {1, 2, 3, 4, 5};
    for (int i = 0; i < N; ++i)
        // ������β�����룬����
        if(!insertInPost(&List1, arry[i])){
            cout << "Error!" << endl;
            return 1;
        }

    ListNode *tail = List1;

    while(tail->next)
        tail = tail->next;
    tail->next = List1->next;

    //traverse(&List1);

    Solution A;
    ListNode *ans = A.detectCycle(List1);
    traverse(&ans);

    return 0;
}
