#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int StDataType;
typedef struct Stack
{
	StDataType* arr;
	int top;//栈顶
	int capacity;
}Stack;
//初始化栈
void StackInit(Stack* st);
//销毁栈
void StackDestory(Stack* st);
//入栈
void StackPush(Stack* st, StDataType x);
//出栈
void StackPop(Stack* st);
int StackSize(Stack* st);
//栈为空返回1
int StackEmpty(Stack* st);
//获取栈顶元素
StDataType StackTop(Stack* st);
