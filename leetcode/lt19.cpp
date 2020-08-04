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

class lt19 : public lt
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (NULL == head)
        {
            return head;
        }

        ListNode *pre, *p;
        p = head;
        pre = head;
        while (NULL != p->next)
        {
            if (--n < 0)
            {
                pre = pre->next;
            }

            p = p->next;
        }
        if (n <= 0) //这里要注意判定 p指针到末尾时，pre指针是否为选中状态，选中状态表示要p指针到底，pre指针刚巧指到第一个节点
        {
            pre->next = pre->next->next;
        }
        else
        {
            ListNode *rlt = pre->next;
            pre->next = NULL;
            return rlt;
        }

        return head;
    }

    void run() override
    {
        long begin, end;
        begin = getTimeUsec();

        /** test code begin **/

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