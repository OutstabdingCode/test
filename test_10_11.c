#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ϲ�������������



  struct ListNode {
   int val;
   struct ListNode *next;
 };
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    //�Գ��ֿ��������������ж�
    if (pHead1 == NULL)
    {
        return pHead2;
    }
    if (pHead2 == NULL)
    {
        return pHead1;
    }
    //����һ����ͷ���Ŀ���������Ϊ���ص�ֵ
    struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode->next = NULL;
    //struct ListNode* HeadNode = NewNode;
    //��������������β���
    struct ListNode* TailNode = NewNode;
    //�������ƶ�ָ�룬��������
    struct ListNode* Head1Node = pHead1;
    struct ListNode* Head2Node = pHead2;
    //��¼��ǰ�Ľ�����һ�����
    struct ListNode* NextNode = NULL;
    //ע��ѭ�����е�����
    while (Head1Node != NULL && Head2Node != NULL)
    {
        //����β�巨����������
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
    //�Գ�����������ĳ��Ȳ�ͬ���з���
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