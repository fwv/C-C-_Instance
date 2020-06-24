#include <iostream>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

#ifndef LISTNODE_H
#define LISTNODE_H
#include"ds/ListNode.cpp"
#endif

using namespace std;

// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you implement both?

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-linked-list
//Definition for singly-linked list.

void showList(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << " --> " << p->val;
        p = p->next;
    }
    cout << endl;
};

class lt206 : public lt
{
public:
    ListNode *pre,*p,*n;

      ListNode* reverseList(ListNode* head) {
          if(NULL == head)return head; //边界条件判断
          ListNode * p = head->next;
          head->next = NULL;  //head头结点断链
         return recursivelyR(head, p);
      }
    
    ListNode* recursivelyR(ListNode* pre, ListNode* p) {
       if (NULL == p || NULL == pre)
       {
           return pre;
       }
       ListNode* n = p -> next;
       p->next = pre;
       recursivelyR(p, n);
    }

    ListNode* iterativelyR(ListNode* head) {
         if(NULL == head || NULL == head->next)return head;//边界条件判断
         pre = head;
         p = pre->next;
         n = p->next;
         pre->next = NULL; //head头结点断链

         while (NULL != p)
         {   
             p->next = pre;
             pre = p;
             p = n;
             if (NULL!=n)
             {
               n = n->next;
             }
            
         }
         return pre;
    }

    void run() override
    {
        ListNode head = ListNode(-1);
        ListNode n1 = ListNode(1);
        ListNode n2 = ListNode(2);
        ListNode n3 = ListNode(3);
        ListNode n4 = ListNode(4);
        ListNode n5 = ListNode(5);
        head.next = &n1;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        showList(&head);
        ListNode *newHead = reverseList(&head);
        showList(newHead);
    }
};