/*
 * ջ�Ͷѵ�����http://blog.csdn.net/hairetz/article/details/4141043
 * C++��new����������ͷ�new���������������http://www.cnblogs.com/GODYCA/archive/2013/01/10/2854777.html
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
        // ��������ע�͵Ĵ����Ǵ���ģ���ֻ����ѭ����ÿ�ζ���һ���ֲ������������ջ����ͬ��λ�ã������node->next = &node�����������Ի�������ÿһ��ѭ������Щ�洢��Ԫ�ᱻϵͳ�Զ��ͷš�
        //ListNode node(i);
        //tail->next = &node;

        // ������ȷ�ķ�������new���ڶ��з������ڴ棬�������ڴ�ķ�����ͷű����ɳ���Ա�ֶ��ͷš�
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
