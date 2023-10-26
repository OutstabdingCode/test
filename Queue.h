#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int	QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QueueNode;
typedef struct Queue
{
	QueueNode* tail;
	QueueNode* head;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
//1ЮЊПе
int QueueEmpty(Queue* pq);