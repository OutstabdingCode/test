#include "Stack.h"
void StackInit(Stack* st)
{
	st->arr = (StDataType*)malloc(sizeof(StDataType) * 5);
	st->capacity = 5;
	st->top = 0;
}
void StackDestory(Stack* st)
{
	free(st->arr);
	st->arr = NULL;
	st->capacity = 0;
	st->top = 0;
}
void StackPush(Stack* st, StDataType x)
{
	assert(st);
	if (st->top >= st->capacity)
	{
		st->capacity *= 2;
		StDataType* temp = (StDataType*)realloc(st->arr, sizeof(StDataType) * st->capacity);
		if (temp == NULL)
		{
			printf("ÄÚ´æ²»×ã\n");
			exit(1);
		}
		else
		{
			st->arr = temp;
		}
	}
	st->arr[st->top] = x;
	(st->top)++;

}
void StackPop(Stack* st)
{
	assert(st);
	(st->top)--;
}
int StackSize(Stack* st)
{
	assert(st);
	return st->top;
}
int StackEmpty(Stack* st)
{
	return st->top == 0 ? 1 : 0;
}
StDataType StackTop(Stack* st)
{
	assert(st);
	return st->arr[st->top - 1];
}