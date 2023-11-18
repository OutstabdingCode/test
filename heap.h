#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* _arr;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap* php, HeapDataType* arr, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HeapDataType* x);
void HeapPop(Heap* php);
HeapDataType HeapTop(Heap* php);
void Swap(HeapDataType* x, HeapDataType* y);
void AdjustDown(HeapDataType* arr, int n, int root);