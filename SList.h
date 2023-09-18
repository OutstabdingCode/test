#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLlistDataType;
typedef struct SList
{
	//������
	SLlistDataType data;
	//ָ����
	struct SList* next;
}SList;

//β�巨
void SListTailInsert(SList** phead, SLlistDataType x);
//ͷ�巨
void SListHeadInsert(SList** phead, SLlistDataType x);
//��������
void SListSearchData(SList* phead, SLlistDataType x);
//βɾ����
void SListTailDelete(SList** phead);
//ͷɾ����
void SListHeadDelete(SList** phead);
//�����������
void SListRandomInsert(SList** phead, SLlistDataType x, int address);//�����λ��
//����ɾ������
void SListRandomDelete(SList** phead, int address);
//�������
void ShowSList(SList* phead);
//�����ڴ�
SList* CreatStorage();
