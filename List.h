#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct List
{
	struct List* prev;
	DataType val;
	struct List* next;
}List;
//开辟内存
List* CreateSpace();
//初始化链表
void ListInit(List** phead);//注意传二级指针
//尾插
void TailInsert(List* phead, DataType x);
//打印链表
void ShowList(List* phead);
//头插
void HeadInsert(List* phead, DataType x);
//头删
void HeadDel(List* phead);
//尾删
void TailDel(List* phead);
//查找
void SearchNode(List* phead, DataType x);