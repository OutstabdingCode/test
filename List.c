#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void SearchNode(List* phead, DataType x)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		//������x��ͬ��val
		if (cur->val == x)
		{
			printf("%d ", cur->val);
			return;
		}
		else
		{
			cur = cur->next;//����ƶ�
		}
	}
	printf("searching is failure!\n");
}
void TailDel(List* phead)
{
	assert(phead);
	assert(phead->prev != phead);
	List* tail = phead->prev;
	List* tailPrev = tail->prev;//��¼β������һ�����

	//ָ���ͷ������ѭ������
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
}
void HeadDel(List* phead)
{
	assert(phead);
	//����Ϊ��ʱ����ɾ�����
	assert(phead->next != phead);
	List* first = phead->next;
	List* next = first->next;//��¼��һ��������һ�����

	//����������>=2ʱ���������ӱ�ͷ
	//����������<2ʱ���������ӳ�ѭ������
	phead->next = next;
	next->prev = phead;
	free(first);
}
List* CreateSpace()
{
	List* Node = (List*)malloc(sizeof(struct List));
	assert(Node);//�����ڴ�û���ٳɹ�
	Node->prev = NULL;
	Node->next = NULL;
	return Node;
}
void TailInsert(List* phead, DataType x)
{
	assert(phead);
	List* newNode = CreateSpace();
	newNode->val = x;
	List* Tail = phead->prev;
	//���½���prevָ�������βָ��
	newNode->prev = Tail;
	newNode->next = phead;//ָ���ͷ������ѭ������

	Tail->next = newNode;//�½��������β���ĺ���
	phead->prev = newNode;//ָ���½�㣬����ѭ������
	
}
void ListInit(List** phead)
{
	assert(*phead);
	(*phead)->next = (*phead);
	(*phead)->prev = (*phead);
}
void ShowList(List* phead)
{
	if (phead->next == phead)
	{
		printf("NULL");
		return;
	}
	List* cur = phead->next;
	while (cur != phead)//ע��ѭ��������������ֹ��ѭ��
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");

}
void HeadInsert(List* phead, DataType x)
{
	assert(phead);
	List* first = phead->next;
	List* tail = phead->prev;
	List* newNode = CreateSpace();
	newNode->val = x;
	//���۸ô�ͷ�������Ƿ��н�㶼����
	phead->next = newNode;//��ͷ�����½��
	newNode->prev = phead;//�½�����ӱ�ͷ

	//���������н��ʱ����������������໥���Ӻ���Ľ��
	//��������û�н��ʱ��������������ǹ���ѭ������
	newNode->next = first;
	first->prev = newNode;
	
}