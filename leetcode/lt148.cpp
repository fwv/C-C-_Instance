#ifndef LT_H
#define LT_H
#include "lt.cpp"
#endif

#ifndef LISTNODE_H
#define LISTNODE_H
#include"ds/ListNode.cpp"
#endif

using namespace std;

class lt148 : public lt
{
public:
    ListNode *sortList(ListNode *head)
    {   
       if (NULL == head || NULL == head->next)return head;
       ListNode* pre = head;
       ListNode* p = head ->next;
       while(p) {
           pre = p;
           p = p->next;
       }
      return mergeSort(head, pre);
    }

    ListNode* mergeSort(ListNode *low, ListNode *high) {
        if(NULL == low ->next || NULL == high || low == high) return low;
        ListNode *slow = low;
        ListNode *fast = low;
        ListNode *pre;
        while (fast != high && NULL != fast)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (NULL == fast)
        {
            slow = pre;
        }
        ListNode* low2 = slow->next;
        slow->next = NULL;
        ListNode*l1 = mergeSort(low, slow);
        ListNode*l2 = mergeSort(low2, high);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode * head = new ListNode;
        ListNode * p  = head;
        while (NULL!= l1 && NULL !=l2)
        {
            if (l1->val < l2->val)
            {
                ListNode *temp = l1 -> next;
                l1 -> next = NULL;
                p -> next  = l1;
                l1 = temp;
            }else
            {
                ListNode *temp = l2 -> next;
                l2 -> next = NULL;
                p -> next  = l2;
                l2 = temp;
            }
            p = p->next;
        }
        if (NULL == l1)
        {
            p->next = l2;
        } else
        {
            p->next = l1;
        }
        ListNode *rlt = head -> next;
        head->next = NULL;
        return rlt;
    }

    // 插入排序思想 O(n2)达不到要求
    //     ListNode *sortList(ListNode *head)
    // {
    //     ListNode *newHead, *oldHead, *p;
    //     //边界判断
    //     if (NULL == head || NULL == head->next)
    //     {
    //         return head;
    //     }

    //     //1.建立头结点，规格化每一个节点操作
    //     newHead = new ListNode(-999);
    //     //2.向头结点插入新节点比较大小
    //     p = head;
    //     oldHead = head->next;
    //     while (p != NULL)
    //     {
    //         p->next = NULL;
    //         //插入新链表
    //         ListNode *pre = newHead;
    //         ListNode *temp = newHead->next;
    //         while (NULL != temp)
    //         {
    //             if (p->val > temp->val)
    //             {
    //                 pre = temp;
    //                 temp = temp->next;
    //             } else
    //             {
    //                 break;
    //             }
                
    //         }
    //         p->next = temp;
    //         pre->next = p;

    //         //工作节点移动
    //         p = oldHead;
    //         if (oldHead != NULL)
    //             oldHead = oldHead->next;
    //     }
    //     return newHead->next;
    // }

    void run() override
    {
        ListNode head = ListNode(4);
        ListNode n1 = ListNode(2);
        ListNode n2 = ListNode(1);
        ListNode n3 = ListNode(3);
        // ListNode n4 = ListNode(1);
        // ListNode n5 = ListNode(-1);
        head.next = &n1;
        n1.next = &n2;
        n2.next = &n3;
        // n3.next = &n4;
        // n4.next = &n5;
        showList(&head);
        ListNode *newHead = sortList(&head);
        showList(newHead);
    }

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
};