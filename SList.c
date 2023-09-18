#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListTailInsert(SList** phead, SLlistDataType x)
{
	
	SList* NewNode;
	SList* TailNode;
	//������Ϊ������
	if ((*phead)->next == NULL)
	{
		NewNode = CreatStorage();
		NewNode->data = x;
		NewNode->next = NULL;
		(*phead)->next = NewNode;
	}
	//����Ϊ��
	else
	{
		TailNode = (*phead);
		//����β�ڵ�
		while (TailNode->next != NULL)
		{
			TailNode = TailNode->next;
		}
		NewNode = CreatStorage();
		NewNode->data = x;
		NewNode->next = TailNode->next;
		TailNode->next = NewNode;
	}
}
void SListHeadInsert(SList** phead, SLlistDataType x)
{
	SList* NewNode = CreatStorage();
	NewNode->data = x;
	NewNode->next = (*phead)->next;
	(*phead)->next = NewNode;
}
void SListSearchData(SList* phead, SLlistDataType x)
{
	SList* SearchNode = phead->next;
	int flag = 0;
	while (SearchNode != NULL)
	{
		if (SearchNode->data == x)
		{
			flag = 1;
			printf("%d ", SearchNode->data);
			break;
		}
		else
		{
			SearchNode = SearchNode->next;
		}
		
	}
	if(!flag)
		printf("û���������\n");
}
void SListTailDelete(SList** phead)
{
	SList* TailNode;
	//��¼β��ڵ��ǰһ���ڵ�
	SList* PriorNode = NULL;
	//��ָ������ĵ�һ���ڵ㣬֮��ʼ�ƶ���β�ڵ�
	TailNode = (*phead)->next;
	while (TailNode->next != NULL)
	{
		PriorNode = TailNode;
		TailNode = TailNode->next;
	}
	PriorNode->next = TailNode->next;
}
void SListHeadDelete(SList** phead)
{
	SList* FirstNode = (*phead)->next;
	(*phead)->next = FirstNode->next;
	FirstNode->next = NULL;
}
void SListRandomInsert(SList** phead, SLlistDataType x, int address)
{
	int count = 0;
	int flag = 0;
	SList* SearchNode = NULL;
	SList* PriorNode = (*phead);
	SList* NewNode = CreatStorage();
	SearchNode = (*phead)->next;
	//�Ѿ�ָ���һ���ڵ�
	count = 1;
	while (SearchNode != NULL)
	{
		
		if (count == address)
		{
			flag = 1;
			NewNode->data = x;
			NewNode->next = PriorNode->next;
			PriorNode->next = NewNode;
			break;
		}
		else
		{
			PriorNode = SearchNode;
			SearchNode = SearchNode->next;
			count++;
		}
	}
	if (!flag)
	{
		printf("�������޸ýڵ�\n");
	}
}
void SListRandomDelete(SList** phead, int address)
{
	int count = 0;
	int flag = 0;
	SList* SearchNode = NULL;
	SList* PriorNode = (*phead);
	SList* NewNode = CreatStorage();
	SearchNode = (*phead)->next;
	//�Ѿ�ָ���һ���ڵ�
	count = 1;
	while (SearchNode != NULL)
	{

		if (count == address)
		{
			flag = 1;
			PriorNode->next = SearchNode->next;
			SearchNode->next = NULL;
			break;
		}
		else
		{
			PriorNode = SearchNode;
			SearchNode = SearchNode->next;
			count++;
		}
		
	}
	if (!flag)
	{
		printf("�������޸ýڵ�\n");
	}

}
void ShowSList(SList* phead)
{
	if (phead->next == NULL)
	{
		return;
	}
	else
	{
		phead = phead->next;
		while (phead != NULL)
		{
			printf("%d->", phead->data);
			phead = phead->next;
			
		}
		printf("NULL");
	}
}
SList* CreatStorage()
{
	SList* SLNode = NULL;
	SLNode = (SList*)malloc(sizeof(SList));
	return SLNode;
}