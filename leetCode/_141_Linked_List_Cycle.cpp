/**
 * LeetCode 141 Linked List Cycle.
 * https://leetcode.com/problems/linked-list-cycle/
 */

#include "singlyLinkedList.h"


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 设立快慢指针，快指针每次走两步，慢指针每次走一步。
        // 假设慢指针在前，快指针在后，这样相当于快指针每次往慢指针靠近一步。
        // 若指针为空，则无环；若快指针等于慢指针，则有环。
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
        // 单链表尾部插入，正序。
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
