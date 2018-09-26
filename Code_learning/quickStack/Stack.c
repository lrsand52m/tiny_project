#include "Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (DataType*)malloc(sizeof(Stack)* 3);
	ps->capacity = 3;
	ps->top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->data)
		free(ps->data);
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->data = (DataType*)realloc(ps->data, sizeof(Stack)*(ps->capacity * 2));
		if (ps->data)
			ps->capacity *= 2;
		else perror("capacity realloc");
	}
	*(ps->data + ps->top++) = x;
}
void StackPop(Stack* ps)
{
	assert(ps&&ps->data);
	if (ps->top)
		ps->top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps&&ps->data&&ps->top);
	return *(ps->data + ps->top - 1);
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top != 0;
}
int StackSize(Stack* ps)
{
	assert(ps&&ps->data);
	return ps->top;
}
void TestStack()
{
	Stack s;
	int i = 0;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size:%d\n", StackSize(&s));
	printf("empty:%d\n", StackEmpty(&s));
	for (i = 0; i < 5; i++)
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	printf("size:%d\n", StackSize(&s));
	printf("empty:%d\n", StackEmpty(&s));
	StackDestory(&s);
}