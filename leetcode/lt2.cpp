#include <iostream>
#include <algorithm>

#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

#ifndef LISTNODE_H
#define LISTNODE_H
#include"ds/ListNode.cpp"
#endif

using namespace std;

// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

class lt2 : public lt
{
public:
    int r = 0;
    ListNode* tail;
    ListNode* head; //不要用空指针指向空指针，这样当第二个空指针指向实值时第一个仍然为空


    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {   
        while (l1 != NULL && l2 != NULL)  // 相同长度先火拼
        {
            int temp = l1->val + l2->val + r;
            if (temp >= 10)
            {
                r = temp / 10;
                temp = temp % 10;
            } else
            {
                r = 0;  // 调试点2：进位要清零 
            }
            

            ListNode * newNode = new ListNode;
            newNode->val = temp;

            if (NULL == tail)
            {   
                head = newNode; //调试点1
                tail = newNode;
            } else
            {
                tail -> next = newNode;
                tail = newNode;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (l1 == NULL && l2 == NULL)  // 两链表长度相同
        {
            if (0!=r) // 处理最高位进位
            {
                ListNode * newNode = new ListNode;
                newNode->val = r;
                tail -> next = newNode;
            }
            
        } 

        if (l1 != NULL && l2 == NULL)  // l1未尽
        {
            if (r==0)   //最高无进位
            {
                tail -> next = l1;
            } else
            {
                while (l1 != NULL && r != 0)
                {
                    int temp = r + l1 -> val;
                    if (temp >= 10)
                    {
                        r = temp / 10;
                        temp = temp % 10;
                    }else
                    {
                        r = 0;
                    }
                    l1 -> val = temp;
                    tail -> next = l1;
                    tail = l1;
                    l1 = l1 -> next;
                }
                if (r != 0)
                {
                    ListNode * newNode = new ListNode;
                    newNode->val = r;
                    tail -> next = newNode;
                }
                
            }
        } else // l2未尽
        {
            if (r==0)
            {
                tail -> next = l2;
            } else
            {
                while (l2 != NULL && r != 0)
                {
                    int temp = r + l2 -> val;
                    if (temp >= 10)
                    {
                        r = temp / 10;
                        temp = temp % 10;
                    }else
                    {
                        r = 0;
                    }
                    l2 -> val = temp;
                    tail -> next = l2;
                    tail = l2;
                    l2 = l2 -> next;
                }
                if (r != 0)  //处理最末最高进位
                {
                    ListNode * newNode = new ListNode;
                    newNode->val = r;
                    tail -> next = newNode;
                }
                
            }
        }
        return head;
    }

    void run() override
    {
        ListNode* l1 = new ListNode(9);
        ListNode* l2 = new ListNode(9);
        ListNode* l3 = new ListNode(9);
        l1 -> next = l2;
        l2 -> next = l3;
        l3 -> next = NULL;

        ListNode* n1 = new ListNode(1);
        // ListNode* n2 = new ListNode(0);
        // ListNode* n3 = new ListNode(0);
        // n1 -> next = n2;
        // n2 -> next = n3;
        // n3 -> next = NULL;

        ListNode * rlt = addTwoNumbers(l1, n1); 
        cout<< endl;
    }
};