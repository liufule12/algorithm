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
        minStack = new ListNode(INT_MAX);
    }

    void push(int x) {
        ListNode *newData = new ListNode(x);
        newData->next = minStack->next;
        minStack->next = newData;

        // If the pushed element is smaller than the current minimum, then change the minimum value.
        if (x < minStack->val)
            minStack->val = x;
    }

    void pop() {
        if (!minStack->next)
            return ;

        ListNode *p = minStack->next;
        minStack->next = minStack->next->next;

        // If the popped element is the same as the current minimum, then find the new minimum value.
        if (p->val == minStack->val){
            minStack->val = INT_MAX;
            ListNode *q = minStack->next;
            while(q){
                if (q->val < minStack->val)
                    minStack->val = q->val;
                q = q->next;
            }
        }
        free(p);
    }

    int top() {
        if (minStack->next)
            return minStack->next->val;
        return NULL;
    }

    int getMin() {
        if (minStack->next)
            return minStack->val;
        return NULL;
    }

    ListNode *getMinStack() {
        return minStack;
    }

private:
    ListNode *minStack;
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
