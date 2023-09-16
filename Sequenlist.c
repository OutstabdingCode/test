#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequenlist.h"
void SetSequenlist(Sequenlist* p)
{
	p->arr = (Sequenlist*)malloc(sizeof(Sequenlist) * 4);
	if (p->arr == NULL)
	{
		printf("内存开辟失败!!");
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
		//注意realloc如果空间充足则在原因的空间上扩大，否则将重新开辟一块空间，并释放原有的空间
		p->arr = (Sequenlist*)realloc(p->arr, sizeof(Sequenlist) * p->capacity);
		if (p->arr == NULL)
		{
			printf("内存开辟失败!!");
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
			printf("内存开辟失败!!");
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
void RandomInsert(Sequenlist* p, DataType x, DataType search/*要查找的数据*/)
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
			printf("内存开辟失败!!");
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
	//这个算法有个缺陷，如果数组中有2个或者2个以上此算法就行不通
	int i = 0;
	//利用遍历数组的方式寻找，也可以用二分查找
	for (i = 0; i < p->size; i++)
	{
		if (p->arr[i] == x)
		{
			return &p->arr[i];
		}
	}
	if (i == p->size)
	{
		printf("没有这个数据\n");
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