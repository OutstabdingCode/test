#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLlistDataType;
typedef struct SList
{
	//数据域
	SLlistDataType data;
	//指针域
	struct SList* next;
}SList;

//尾插法
void SListTailInsert(SList** phead, SLlistDataType x);
//头插法
void SListHeadInsert(SList** phead, SLlistDataType x);
//查找数据
void SListSearchData(SList* phead, SLlistDataType x);
//尾删数据
void SListTailDelete(SList** phead);
//头删数据
void SListHeadDelete(SList** phead);
//任意插入数据
void SListRandomInsert(SList** phead, SLlistDataType x, int address);//插入的位置
//任意删除数据
void SListRandomDelete(SList** phead, int address);
//链表输出
void ShowSList(SList* phead);
//开辟内存
SList* CreatStorage();
