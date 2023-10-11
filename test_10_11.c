#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//合并两个有序链表



  struct ListNode {
   int val;
   struct ListNode *next;
 };
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    //对出现空链表的情况进行判断
    if (pHead1 == NULL)
    {
        return pHead2;
    }
    if (pHead2 == NULL)
    {
        return pHead1;
    }
    //建立一个带头结点的空链表，并作为返回的值
    struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode->next = NULL;
    //struct ListNode* HeadNode = NewNode;
    //用来标记新链表的尾结点
    struct ListNode* TailNode = NewNode;
    //用来作移动指针，遍历链表
    struct ListNode* Head1Node = pHead1;
    struct ListNode* Head2Node = pHead2;
    //记录当前的结点的下一个结点
    struct ListNode* NextNode = NULL;
    //注意循环进行的条件
    while (Head1Node != NULL && Head2Node != NULL)
    {
        //利用尾插法，插人数据
        if (Head1Node->val <= Head2Node->val)
        {
            NextNode = Head1Node->next;
            Head1Node->next = TailNode->next;
            TailNode->next = Head1Node;
            TailNode = Head1Node;
            Head1Node = NextNode;


        }
        else
        {
            NextNode = Head2Node->next;
            Head2Node->next = TailNode->next;
            TailNode->next = Head2Node;
            TailNode = Head2Node;
            Head2Node = NextNode;

        }
    }
    //对出现两个链表的长度不同进行分类
    if (Head1Node == NULL && Head2Node != NULL)
    {
        TailNode->next = Head2Node;
    }
    if (Head1Node != NULL && Head2Node == NULL)
    {
        TailNode->next = Head1Node;
    }

    return NewNode->next;




}