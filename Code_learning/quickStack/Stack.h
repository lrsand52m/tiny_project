#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* data;
	int top;		// Õ»¶¥
	int capacity;  // ÈÝÁ¿ 
}Stack;
typedef struct StackM
{
	Stack data;
	Stack min;
}StackM;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void TestStack();
void TestMin();
void StackPushM(StackM* ps, DataType x);
void StackPopM(StackM* ps);
DataType StackMin(StackM* ps);

