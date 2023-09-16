#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequenlist.h"
void SetSequenlist(Sequenlist* p)
{
	p->arr = (Sequenlist*)malloc(sizeof(Sequenlist) * 4);
	if (p->arr == NULL)
	{
		printf("�ڴ濪��ʧ��!!");
		return;
	}
	p->size = 0;
	p->capacity = 4;
}
void RearInsert(Sequenlist* p, DataType x)
{
	if (p->size >= p->capacity)
	{
		p->capacity *= 2;
		//ע��realloc����ռ��������ԭ��Ŀռ������󣬷������¿���һ��ռ䣬���ͷ�ԭ�еĿռ�
		p->arr = (Sequenlist*)realloc(p->arr, sizeof(Sequenlist) * p->capacity);
		if (p->arr == NULL)
		{
			printf("�ڴ濪��ʧ��!!");
			return;
		}
	}
	p->arr[p->size] = x;
	p->size++;
}
void HeadInsert(Sequenlist* p, DataType x)
{
	int i = 0;
	if (p->size + 1 >= p->capacity)
	{
		p->capacity *= 2;
		p->arr = (Sequenlist*)realloc(p->arr, sizeof(Sequenlist) * p->capacity);
		if (p->arr == NULL)
		{
			printf("�ڴ濪��ʧ��!!");
			return;
		}
	}
	for (i = p->size; i > 0; i--)
	{
		p->arr[i] = p->arr[i - 1];
	}
	p->arr[i] = x;
	p->size++;
}
void RandomInsert(Sequenlist* p, DataType x, DataType search/*Ҫ���ҵ�����*/)
{
	int i = 0;
	DataType* d = NULL;
	d = SreachData(p, search);
	int start = d - p->arr;
	if (p->size + 1 >= p->capacity)
	{
		p->capacity *= 2;
		p->arr = (Sequenlist*)realloc(p->arr, sizeof(Sequenlist) * p->capacity);
		if (p->arr == NULL)
		{
			printf("�ڴ濪��ʧ��!!");
			return;
		}
	}
	for (i = p->size; i > start; i--)
	{
		p->arr[i] = p->arr[i - 1];
	}
	p->arr[i] = x;
	p->size++;
}
void RearDelete(Sequenlist* p)
{
	p->size--;
}
void HeadDelete(Sequenlist* p)
{
	for (int i = 0; i < p->size; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}
void RandomDelete(Sequenlist* p, int x)
{
	for (int i = x; i < p->size; i++)
	{
		p->arr[i - 1] = p->arr[i];
	}
	p->size--;
}
DataType* SreachData(Sequenlist* p, DataType x)
{
	//����㷨�и�ȱ�ݣ������������2������2�����ϴ��㷨���в�ͨ
	int i = 0;
	//���ñ�������ķ�ʽѰ�ң�Ҳ�����ö��ֲ���
	for (i = 0; i < p->size; i++)
	{
		if (p->arr[i] == x)
		{
			return &p->arr[i];
		}
	}
	if (i == p->size)
	{
		printf("û���������\n");
		return;
	}
	
}
void ShowSequenlist(Sequenlist* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
}