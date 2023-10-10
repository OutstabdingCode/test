#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*      ��ת����         */
 struct ListNode 
 {
 	int val;
 	struct ListNode *next;
  };
 //�ⷨ1��ͷ�巨
struct ListNode* ReverseList(struct ListNode* head)
{
    
    //����һ���µ���������ͷ�巨
    //struct ListNode* NewNode = NULL;
    //���и�����
    //���ָ�����������صģ�������ؾֲ������ĵ�ַ���ǻ᲻�������Ƿ��ڴ���ʣ���
    struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode = NULL;
    //��¼ʵ�εı�ͷ��������������
    struct ListNode* NowNode = head;
    //���Ϊ������ֱ�ӷ����µ�������
    while (NowNode != NULL)
    {
        //��¼��ǰ������һ�����
        struct ListNode* NextNode = NowNode->next;

        //ͷ������
        NowNode->next = NewNode;
        //���¿��������ͷ�ƶ�
        NewNode = NowNode;

        //�ƶ�ʵ�εĽ��
        NowNode = NextNode;
    }
    return NewNode;
/******************************************************************************************/
    //�ⷨ2��ָ���ƶ�
//FrontNode��Ϊ��������ĵ�һ�����
    struct ListNode* FrontNode = malloc(sizeof(struct ListNode));
    FrontNode = NULL;
    //���������βεĵ�һ�����
    struct ListNode* NowNode = head;

    while (NowNode != NULL)
    {
        //������ת����

        //��¼��һ������λ��
        struct ListNode* NextNode = NowNode->next;
        //��ת����
        NowNode->next = FrontNode;
        //�������
        FrontNode = NowNode;
        NowNode = NextNode;
    }
    return FrontNode;

}
/*************************************************************************************/
//������ָ�����䷴ת
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    //������Ϊ�գ�������Ҫ��ת�����䷶ΧΪ0�Ƿ��ظ�����
    if (head == NULL || m == n)
    {
        return head;
    }
    //�����µ�һ����ͷ���
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    //��������,����������ֵ
    pHead = head;
    //��¼��m - 1�����
    struct ListNode* PriorNode = head;

    //�����ҵ�M��ָ��
    for (int i = 0; i < m - 1; i++)
    {

        PriorNode = head;
        //��¼��m�����
        head = head->next;
    }
    //������ʱ��¼
    struct ListNode* TempNode = NULL;
    //��ת��ͷ�ڵ�
    struct ListNode* HeadNode = head;
    //��ת��β���
    struct ListNode* NextNode = head->next;
    for (int i = 0; i < n - m; i++)
    {
        //ͷ�巴ת����
        TempNode = NextNode->next;
        NextNode->next = head;
        head = NextNode;
        NextNode = TempNode;

    }
    //��������
    PriorNode->next = head;
    HeadNode->next = NextNode;
    //����ת��ʼ���Ϊ1ʱ,��Ҫ���ط�ת���ͷ���
    if (m == 1)
        return head;
    else
        return pHead;
}