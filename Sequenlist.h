#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Sequenlist
{
	DataType* arr;
	//有效数据的个数
	int size;
	//顺序表的容量
	int capacity;
}Sequenlist;
//初始化结构体
void SetSequenlist(Sequenlist* p);
//尾部插入法
void RearInsert(Sequenlist* p, DataType x);
//头插法
void HeadInsert(Sequenlist* p, DataType x);
//随机插入法
void RandomInsert(Sequenlist* p, DataType x, DataType search);
//尾删法
void RearDelete(Sequenlist* p);
//头删法
void HeadDelete(Sequenlist* p);
//随机删除数据
void RandomDelete(Sequenlist* p, int x);
//获取指定数据
DataType* SreachData(Sequenlist* p, DataType x);
void ShowSequenlist(Sequenlist* p);
