#include <iostream>
#include <algorithm>
#include <vector>
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

class lt23 : public lt
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size()-1);
    }

    //采用归并方法合并k个有序链表
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        ListNode *left = merge(lists, l, mid);
        ListNode *right = merge(lists, mid + 1, r);
        return merge2Lists(left, right);
    }

    ListNode *merge2Lists(ListNode *left, ListNode *right)
    {
        if (NULL == left || NULL == right)
            return left ? left : right;
        ListNode *head = new ListNode(), *tail = head;
        while (NULL != left && NULL != right)
        {
            ListNode *temp = NULL;
            if (left->val < right->val)
            {
                temp = left;
                left = left->next;
            }
            else
            {
                temp = right;
                right = right->next;
            }
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }
        if (left != NULL)
        {
            tail->next = left;
        }
        if (right != NULL)
        {
            tail->next = right;
        }
        return head->next;
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