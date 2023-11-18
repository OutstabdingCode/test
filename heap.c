#include "heap.h"
void Swap(HeapDataType* x, HeapDataType* y)
{
	HeapDataType temp = *x;
	*x = *y;
	*y = temp;
}
void AdjustDown(HeapDataType* arr, int n, int root)
{
	int parent = root;//根结点
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		//注意右孩子不能超出数组大小
		if ( (child + 1 < n) && (arr[child + 1] < arr[child]))
		{
			child++;//寻找左右孩子中最小的数
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* php, HeapDataType* arr, int n)
{
	assert(php);
	php->_arr = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	if (php->_arr == NULL)
	{
		printf("内存不足\n");
		exit(1);
	}
	//数组的数据拷贝到堆中
	memcpy(php->_arr, arr, sizeof(HeapDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//构造堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_arr, php->_size, i);
	}
}
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_arr);
	php->_arr = NULL;
	php->_capacity = php->_size = 0;
}
void AdjustUp(HeapDataType* arr, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] > arr[child])//小堆
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* php, HeapDataType* x)
{
	assert(php);
	if (php->_size == php->_capacity)//扩容
	{
		php->_capacity *= 2;
		HeapDataType* temp = (HeapDataType*)realloc(php->_arr, 
			sizeof(HeapDataType) * php->_capacity);
		assert(temp);
		php->_arr = temp;
	}
	php->_arr[php->_size++] = x;
	AdjustUp(php->_arr, php->_size, php->_size - 1);
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_arr[0], &php->_arr[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_arr, php->_size, 0);
}
HeapDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_arr[0];
}
