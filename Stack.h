#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int StDataType;
typedef struct Stack
{
	StDataType* arr;
	int top;//ջ��
	int capacity;
}Stack;
//��ʼ��ջ
void StackInit(Stack* st);
//����ջ
void StackDestory(Stack* st);
//��ջ
void StackPush(Stack* st, StDataType x);
//��ջ
void StackPop(Stack* st);
int StackSize(Stack* st);
//ջΪ�շ���1
int StackEmpty(Stack* st);
//��ȡջ��Ԫ��
StDataType StackTop(Stack* st);
