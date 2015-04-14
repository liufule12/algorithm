/**
 * LeetCode 146 LRU Cache.
 * https://leetcode.com/problems/lru-cache/
 * unorder_map(HashMap) + list(doubleLinkedList)
 * For find(key), O(1) by HashMap.
 * For insert and delete, O(1) by doubleLinkedList.
 * list.splice can transfer elements from list to list.
 * Use rbegin() get the last iterator, not end().
 */

#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache{
private:
    struct node{
        int key;
        int val;
        node(int a, int b) : key(a), val(b) {}
    };
    list<node> cacheList;
    unordered_map<int, list<node>::iterator> cacheHashMap;
    int capacity;

    typedef unordered_map<int, list<node>::iterator> myHashMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // list.splice() and rbegin() play a great effect.
    int get(int key) {
        myHashMap::iterator it = cacheHashMap.find(key);
        if (it != cacheHashMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return it->second->val;
        }
        return -1;
    }

    void set(int key, int value) {
        myHashMap::iterator it = cacheHashMap.find(key);
        if (it != cacheHashMap.end()) {
            it->second->val = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
        } else {
            if (cacheHashMap.size() >= capacity) {
                cacheHashMap.erase(cacheList.rbegin()->key);
                cacheList.pop_back();
            }
            cacheList.push_front(node(key, value));
            cacheHashMap.insert({key, cacheList.begin()});
        }
    }

    void traverse() {
        cout << "traverse cacheList: " << endl;
        for (list<node>::iterator it = cacheList.begin(); it != cacheList.end(); ++it)
            cout << it->key << " " << it->val << endl;
        cout << endl;
    }

    void traverseMap () {
        cout << "traverse cacheHashMap: " << endl;
        for (myHashMap::iterator it = cacheHashMap.begin(); it != cacheHashMap.end(); ++it)
            cout << it->first << endl;
        cout << endl;
    }
};


int main()
{
    LRUCache ans(3);
    ans.traverse();
    ans.traverseMap();

    ans.set(1, 10);
    ans.traverse();
    ans.traverseMap();

    ans.set(2, 20);
    ans.traverse();
    ans.traverseMap();

    cout << "ans.get(1): " << ans.get(1) << endl;
    ans.traverse();
    ans.traverseMap();

    ans.set(3, 30);
    ans.traverse();
    ans.traverseMap();

    ans.set(2, 200);
    ans.traverse();
    ans.traverseMap();

    ans.set(4, 4);
    ans.traverse();
    ans.traverseMap();

    cout << "ans.get(1): " << ans.get(1) << endl;
    ans.traverseMap();

    /*LRUCache ans(1);
    ans.set(2, 1);
    cout << ans.get(2) << endl;*/
    return 0;
}

/*
 * unorder_map + doubleLinkedList.
 * 85ms
class LRUCache{
public:
    struct doubleListNode{
        int key;
        int val;
        doubleListNode *next;
        doubleListNode *pre;
        doubleListNode(int a, int b) : key(a), val(b), next(NULL), pre(NULL) {}
    };
    typedef unordered_map<int, doubleListNode*> myHashMap;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new doubleListNode(-1, -1);
        this->tail = head;
    }

    int get(int key) {
        myHashMap::const_iterator it = cache.find(key);
        if (it != cache.end()) {
            doubleListNode *p = (*it).second;
            if (p->pre == head)
                return (*it).second->val;
            else {
                if (p->next) {
                    p->pre->next = p->next;
                    p->next->pre = p->pre;
                } else {
                    tail = tail->pre;
                    tail->next = NULL;
                }
                p->pre = head;
                p->next = head->next;
                head->next->pre = p;
                head->next = p;

                return (*it).second->val;
            }
        }
        //cout << "Cannot get it!" << endl;
        return -1;
    }

    void set(int key, int value) {
        myHashMap::iterator it = cache.find(key);
        if (it != cache.end()){
            (*it).second->val = value;
            doubleListNode *p = (*it).second;
            if (p->pre == head)
                return ;
            else {
                if (p->next) {
                    p->pre->next = p->next;
                    p->next->pre = p->pre;
                } else {
                    tail = tail->pre;
                    tail->next = NULL;
                }
                p->pre = head;
                p->next = head->next;
                head->next->pre = p;
                head->next = p;
            }
        } else {
            if (cache.size() >= capacity) {
                doubleListNode *p = tail;
                tail = tail->pre;
                tail->next = NULL;
                cache.erase(p->key);
                free(p);
            }
            doubleListNode *p = new doubleListNode(key, value);
            //cout << "cache.size(): " << cache.size() << endl;
            if (0 == cache.size()) {
                head->next = p;
                p->pre = head;
                tail = p;
            } else {
                p->pre = head;
                p->next = head->next;
                head->next->pre = p;
                head->next = p;
            }
            cache.insert({key, p});
        }
    }

    void traverse()
    {
        doubleListNode *p = head;
        while(p != NULL) {
            cout << p->key << " "<< p->val << endl;
            p = p->next;
        }
    }

    void traverseMap()
    {
        cout << "traverseMap" << endl;
        for (auto& it: cache)
            cout << it.second->key << " " << it.second->val << endl;
        cout << endl;
    }

private:
    int capacity;
    doubleListNode *head;
    doubleListNode *tail;
    myHashMap cache;
};
 */


/*
 * Time Limit Exceeded
 *
class LRUCache{
public:
    struct ListNode{
        int key;
        int val;
        ListNode *next;
        ListNode(int a, int b) : key(a), val(b), next(NULL) {}
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new ListNode(0, 0);
    }

    int get(int key) {
        ListNode *p = head;
        while(p->next) {
            if (p->next->key == key) {
                ListNode *q = p->next;
                p->next = p->next->next;
                q->next = head->next;
                head->next = q;
                return q->val;
            }
            p = p->next;
        }
        return -1;
    }

    void set(int key, int value) {
        int count = 0;
        ListNode *p = head;
        ListNode *pre = head;
        while(p->next) {
            if (p->next->key == key) {
                p->next->val = value;
                return ;
            }
            pre = p;
            p = p->next;
            ++count;
        }
        if (count >= capacity){
            pre->next = NULL;
            free(p);
        }

        p = new ListNode(key, value);
        p->next = head->next;
        head->next = p;
    }

    void traverse()
    {
        ListNode *p = head;
        while(p != NULL) {
            cout << p->key << " "<< p->val << endl;
            p = p->next;
        }
        cout << endl;
    }

    ListNode *getHead() {
        return head;
    }
private:
    int capacity;
    ListNode *head;
};
 */
