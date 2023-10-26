#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
void QueuePush(Queue* pq, QDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("ÄÚ´æ²»×ã\n");
		exit(1);
	}
	newNode->val = x;
	newNode->next = NULL;
	if (pq->head == NULL && pq->tail == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->val;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		size++;
		cur = next;
	}
	return size;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL ? 1 : 0;
}