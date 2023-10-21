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
//�����ڴ�
List* CreateSpace();
//��ʼ������
void ListInit(List** phead);//ע�⴫����ָ��
//β��
void TailInsert(List* phead, DataType x);
//��ӡ����
void ShowList(List* phead);
//ͷ��
void HeadInsert(List* phead, DataType x);
//ͷɾ
void HeadDel(List* phead);
//βɾ
void TailDel(List* phead);
//����
void SearchNode(List* phead, DataType x);