/**
 * LeetCode 142 Linked List Cycle II.
 * https://leetcode.com/problems/linked-list-cycle-ii/
 */

#include "singlyLinkedList.h"


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 设立快慢指针，快指针每次走两步，慢指针每次走一步。
        // 假设慢指针在前，快指针在后，这样相当于快指针每次往慢指针靠近一步。
        // 若指针为空，则无环；若快指针等于慢指针，则有环。
        // 根据http://blog.csdn.net/hf81970/article/details/14169655，从表头到环头的距离与快慢指针交点到环头的距离相等。
        // 所以只需表头指针和快慢指针在相交处同时走，表头指针与快慢指针相交点即为环头。
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
        // 单链表尾部插入，正序。
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
