#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void SearchNode(List* phead, DataType x)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		//查找与x相同的val
		if (cur->val == x)
		{
			printf("%d ", cur->val);
			return;
		}
		else
		{
			cur = cur->next;//结点移动
		}
	}
	printf("searching is failure!\n");
}
void TailDel(List* phead)
{
	assert(phead);
	assert(phead->prev != phead);
	List* tail = phead->prev;
	List* tailPrev = tail->prev;//记录尾结点的上一个结点

	//指向表头，构成循环链表
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
}
void HeadDel(List* phead)
{
	assert(phead);
	//链表为空时，不删除结点
	assert(phead->next != phead);
	List* first = phead->next;
	List* next = first->next;//记录第一个结点的下一个结点

	//当链表结点数>=2时，用来连接表头
	//当链表结点数<2时，用来连接成循环链表
	phead->next = next;
	next->prev = phead;
	free(first);
}
List* CreateSpace()
{
	List* Node = (List*)malloc(sizeof(struct List));
	assert(Node);//可能内存没开辟成功
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
	//将新结点的prev指向到链表的尾指针
	newNode->prev = Tail;
	newNode->next = phead;//指向表头，构成循环链表

	Tail->next = newNode;//新结点连接在尾结点的后面
	phead->prev = newNode;//指向新结点，构成循环链表
	
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
	while (cur != phead)//注意循环进行条件，防止死循环
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
	//不论该带头链表中是否有结点都可行
	phead->next = newNode;//表头连接新结点
	newNode->prev = phead;//新结点连接表头

	//当链表中有结点时：下列语句作用是相互连接后面的结点
	//当链表中没有结点时：下列语句作用是构成循环链表
	newNode->next = first;
	first->prev = newNode;
	
}