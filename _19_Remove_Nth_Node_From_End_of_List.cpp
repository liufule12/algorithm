/**
 * LeetCode 19 Remove Nth Node From End of List.
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool insertInFront(ListNode **head, int val)
{
    // 单链表头部插入，倒序。
    struct ListNode *newElem = (ListNode *)malloc(sizeof(struct ListNode));
    if (!newElem)   return false;

    newElem->val = val;
    newElem->next = *head;
    *head = newElem;

    return true;
}

bool insertInPost(ListNode **head, int val)
{
    // 单链表尾部插入，正序。
    struct ListNode *newElem = (ListNode *)malloc(sizeof(struct ListNode));
    if (!newElem)   return false;

    newElem->val = val;
    newElem->next = NULL;
    struct ListNode *tail = *head;
    if (tail == NULL){
        *head = newElem;
        tail = newElem;
    }
    else{
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newElem;
    }

    return true;
}

bool traverse(ListNode **head)
{
    // 遍历链表。
    ListNode *elem = *head;
    while(elem != NULL){
        cout << elem->val << endl;
        elem = elem->next;
    }

    return true;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 设立快慢指针。
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
        // 单链表头部插入，倒序。
        //if(!insertInFront(&List, arry[i])){
        //    cout << "Error!" << endl;
        //    return 1;
        //}
        // 单链表尾部插入，正序。
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
