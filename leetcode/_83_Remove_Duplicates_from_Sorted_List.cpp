/**
 * LeetCode 83 Remove Duplicates from Sorted List.
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    // ������ͷ�����룬����
    ListNode *newElem = (ListNode *)malloc(sizeof(ListNode));
    if (!newElem)   return false;

    newElem->val = val;
    newElem->next = *head;
    *head = newElem;

    return true;
}

bool insertInPost(ListNode **head, int val)
{
    // ������β�����룬����
    ListNode *newElem = (ListNode *)malloc(sizeof(ListNode));
    if (!newElem)   return false;

    newElem->val = val;
    newElem->next = NULL;
    ListNode *tail = *head;
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
    // ��������
    ListNode *elem = *head;
    while(elem != NULL){
        cout << elem->val << endl;
        elem = elem->next;
    }

    return true;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head) {
        // ʹ������ָ�������ɾ���ظ���23ms��
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
        // ���ڵ���������������ֻ��Ҫ�洢1��ָ�룬1�����֣�����ȥ���ظ���������ָ��Ĳ�����20ms��
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

    Solution A;
    ListNode *ans = A.removeNthFromEnd2(List);
    traverse(&ans);

    return 0;
}
