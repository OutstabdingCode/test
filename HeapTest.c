#include "heap.h"
void HeapSort(int* a, int n)
{
	//1¡¢½¨¶Ñ
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
		
	}
	//ÅÅÐò
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int main()
{
	HeapDataType a[] = { 27,16,19,18,28,34,65,49,25,37 };
	//HeapSort(a, sizeof(a) / sizeof(HeapDataType));
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HeapDataType));
	//HeapPush(&hp, 15);
	HeapPop(&hp);
	printf("%d", HeapTop(&hp));
	return 0;
}