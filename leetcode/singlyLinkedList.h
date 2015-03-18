#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

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

#endif // SINGLYLINKEDLIST_H_INCLUDED
