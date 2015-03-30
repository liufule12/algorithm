/*
 * 栈和堆的区别：http://blog.csdn.net/hairetz/article/details/4141043
 * C++用new来创建对象和非new来创建对象的区别：http://www.cnblogs.com/GODYCA/archive/2013/01/10/2854777.html
 */

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


int main()
{
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int i = 0; i < 5; ++i){
        // 下面两行注释的代码是错误的，它只是在循环中每次定义一个局部变量，存放于栈中相同的位置，会出现node->next = &node的情况，造成自环，而且每一次循环后，这些存储单元会被系统自动释放。
        //ListNode node(i);
        //tail->next = &node;

        // 所以正确的方法是用new，在堆中分配了内存，而堆中内存的分配和释放必须由程序员手动释放。
        tail->next = new ListNode(i);
        tail = tail->next;
    }

    ListNode *p = dummy.next;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
