/**
 * LeetCode 237 Delete Node in a Linked List.
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
 */

#include "..\singlyLinkedList.h"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }

    ListNode* deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        delete next;
    }
};


int main()
{
    return 0;
}
