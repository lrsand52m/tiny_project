#include"StackByTwoQueue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_back = pq->_front = NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode *next;
	QueueNode *cur;
	assert(pq);
	cur = pq->_front;
	while (cur)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
}
QueueNode* BuyQueueNode(DataType x)
{
	QueueNode *NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}
void QueuePush(Queue* pq, DataType x)
{
	assert(pq);
	if (pq->_back)
	{
		pq->_back = pq->_back->_next = BuyQueueNode(x);
	}
	else
	{
		pq->_front = pq->_back = BuyQueueNode(x);
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front)
	{
		QueueNode* next = pq->_front->_next;
		free(pq->_front);
		pq->_front = next;
		if (next == NULL)
		{
			pq->_back = NULL;
		}
	}
}
DataType QueueFront(Queue* pq)
{
	assert(pq&&pq->_front);
	return pq->_front->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front != NULL;
}
int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode *cur;
	assert(pq);
	cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue q;
	int i;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	printf("Size:%d\n", QueueSize(&q));
	printf("empty:%d\n", QueueEmpty(&q));
	for (i = 0; i < 6; i++)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\nSize:%d", QueueSize(&q));
	printf("\nempty:%d", QueueEmpty(&q));
	QueueDestory(&q);
}