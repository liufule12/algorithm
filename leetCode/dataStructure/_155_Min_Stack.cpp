/**
 * LeetCode 155 Min Stack.
 * https://leetcode.com/problems/min-stack/
 */

//#include "singlyLinkedList.h"
#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;


class MinStack {

public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    MinStack() {
        // We use the first element store the minimum value.
        head = new ListNode(INT_MAX);
    }

    void push(int x) {
        ListNode *newData = new ListNode(x);
        newData->next = head->next;
        head->next = newData;

        // If the pushed element is smaller than the current minimum, then change the minimum value.
        if (x < head->val)
            head->val = x;
    }

    void pop() {
        if (!head->next)
            return ;

        ListNode *p = head->next;
        head->next = head->next->next;

        // If the popped element is the same as the current minimum, then find the new minimum value.
        if (p->val == head->val){
            head->val = INT_MAX;
            ListNode *q = head->next;
            while(q){
                if (q->val < head->val)
                    head->val = q->val;
                q = q->next;
            }
        }
        free(p);
    }

    int top() {
        if (head->next)
            return head->next->val;
        return NULL;
    }

    int getMin() {
        if (head->next)
            return head->val;
        return NULL;
    }

    ListNode *getMinStack() {
        return head;
    }

private:
    ListNode *head;
};


int main()
{
    MinStack minStack;
    //ListNode *p = minStack.getMinStack();

    minStack.push(3);
    cout << "getTop: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;

    minStack.push(2);
    cout << "getTop: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;

    minStack.push(4);
    cout << "getTop: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;
    //traverse(&p);

    minStack.pop();
    cout << "getTop: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "getTop: " << minStack.top() << endl;
    cout << "getMin: " << minStack.getMin() << endl;


    return 0;
}
