#include"StackByTwoQueue.h"

void StackInit(Stack* ps)
{
	assert(ps);
	QueueInit(&ps->q1);
	QueueInit(&ps->q2);
}
void StackDestory(Stack* ps)
{
	assert(ps);
	QueueDestory(&ps->q1);
	QueueDestory(&ps->q2);
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (QueueEmpty(&ps->q2))
		QueuePush(&ps->q2, x);
	else
		QueuePush(&ps->q1, x);
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(&ps->q1 || &ps->q2);
	if (QueueEmpty(&ps->q1))
	{
		while (QueueSize(&ps->q1) != 1)
		{
			QueuePush(&ps->q2, QueueFront(&ps->q1));
			QueuePop(&ps->q1);
		}
		QueuePop(&ps->q1);
	}
	else
	{
		while (QueueSize(&ps->q2) != 1)
		{
			QueuePush(&ps->q1, QueueFront(&ps->q2));
			QueuePop(&ps->q2);
		}
		QueuePop(&ps->q2);
	}
}
DataType StackTop(Stack* ps)
{
	assert(ps);
	if (QueueEmpty(&ps->q1))
	{
		return (&ps->q1)->_back->_data;
	}
	else if (QueueEmpty(&ps->q2))
	{
		return (&ps->q2)->_back->_data;
	}
	else perror("empty:top");
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return QueueEmpty(&ps->q1) || QueueEmpty(&ps->q2);
}
int StackSize(Stack* ps)
{
	assert(ps);
	return QueueSize(&ps->q1) + QueueSize(&ps->q2);
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