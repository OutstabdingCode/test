#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Sequenlist
{
	DataType* arr;
	//��Ч���ݵĸ���
	int size;
	//˳��������
	int capacity;
}Sequenlist;
//��ʼ���ṹ��
void SetSequenlist(Sequenlist* p);
//β�����뷨
void RearInsert(Sequenlist* p, DataType x);
//ͷ�巨
void HeadInsert(Sequenlist* p, DataType x);
//������뷨
void RandomInsert(Sequenlist* p, DataType x, DataType search);
//βɾ��
void RearDelete(Sequenlist* p);
//ͷɾ��
void HeadDelete(Sequenlist* p);
//���ɾ������
void RandomDelete(Sequenlist* p, int x);
//��ȡָ������
DataType* SreachData(Sequenlist* p, DataType x);
void ShowSequenlist(Sequenlist* p);
