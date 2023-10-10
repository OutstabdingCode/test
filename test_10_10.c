#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*      反转链表         */
 struct ListNode 
 {
 	int val;
 	struct ListNode *next;
  };
 //解法1：头插法
struct ListNode* ReverseList(struct ListNode* head)
{
    
    //建立一个新的链表，利用头插法
    //struct ListNode* NewNode = NULL;
    //这有个疑问
    //这个指针是用来返回的，如果返回局部变量的地址，那会不会引发非法内存访问？？
    struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode = NULL;
    //记录实参的表头，用来遍历链表
    struct ListNode* NowNode = head;
    //如果为空链表，直接返回新的链表结点
    while (NowNode != NULL)
    {
        //记录当前结点的下一个结点
        struct ListNode* NextNode = NowNode->next;

        //头插链表
        NowNode->next = NewNode;
        //将新开辟链表的头移动
        NewNode = NowNode;

        //移动实参的结点
        NowNode = NextNode;
    }
    return NewNode;
/******************************************************************************************/
    //解法2：指针移动
//FrontNode作为返回链表的第一个结点
    struct ListNode* FrontNode = malloc(sizeof(struct ListNode));
    FrontNode = NULL;
    //用来接受形参的第一个结点
    struct ListNode* NowNode = head;

    while (NowNode != NULL)
    {
        //迭代反转链表

        //记录下一个结点的位置
        struct ListNode* NextNode = NowNode->next;
        //反转链表
        NowNode->next = FrontNode;
        //迭代结点
        FrontNode = NowNode;
        NowNode = NextNode;
    }
    return FrontNode;

}
/*************************************************************************************/
//链表内指定区间反转
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    //当链表为空，或者需要反转的区间范围为0是返回该链表
    if (head == NULL || m == n)
    {
        return head;
    }
    //建立新的一个带头结点
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    //连接链表,用来作返回值
    pHead = head;
    //记录第m - 1个结点
    struct ListNode* PriorNode = head;

    //用来找第M个指针
    for (int i = 0; i < m - 1; i++)
    {

        PriorNode = head;
        //记录第m个结点
        head = head->next;
    }
    //用来临时记录
    struct ListNode* TempNode = NULL;
    //反转的头节点
    struct ListNode* HeadNode = head;
    //反转的尾结点
    struct ListNode* NextNode = head->next;
    for (int i = 0; i < n - m; i++)
    {
        //头插反转链表
        TempNode = NextNode->next;
        NextNode->next = head;
        head = NextNode;
        NextNode = TempNode;

    }
    //连接链表
    PriorNode->next = head;
    HeadNode->next = NextNode;
    //当反转开始结点为1时,需要返回反转后的头结点
    if (m == 1)
        return head;
    else
        return pHead;
}