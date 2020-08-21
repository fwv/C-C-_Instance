#include <iostream>
#include <algorithm>
#include <sys/time.h>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

#ifndef LISTNODE_H
#define LISTNODE_H
#include "ds/ListNode.cpp"
#endif

using namespace std;

class lt21 : public lt
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while (NULL != l1 && NULL != l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }  
        if (NULL != l1)
        {
            tail->next = l1;
        }
        if (NULL != l2)
        {
            tail->next = l2;
        }
        return head->next;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/
        ListNode *l1 = new ListNode(1);
        ListNode *l2 = new ListNode(3);
        ListNode *l3 = new ListNode(5);
        ListNode *l4 = new ListNode(7);
        l1->next = l2;
        l2->next = l3;
        l3->next = l4;

        ListNode *r1 = new ListNode(2);
        ListNode *r2 = new ListNode(4);
        ListNode *r3 = new ListNode(6);
        r1->next = r2;
        r2->next = r3;
        ListNode *rlt = mergeTwoLists(l1, r1);
        /** test code end **/

        end = getTimeUsec();

        cout << "程序耗时：" << (end - begin) / 1000 << "ms" << endl;
    }

    long getTimeUsec()
    {
        struct timeval t;
        gettimeofday(&t, 0);
        return (long)((long)t.tv_sec * 1000 * 1000 + t.tv_usec);
    }
};