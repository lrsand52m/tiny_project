#include"Heap.h"
static void Swap(HPDataType*a, HPDataType*b)
{
	HPDataType t = *a;
	*a = *b;
	*b = t;
}
void AdjustDown(HPDataType*a, int n, int parent)
{
	int child;
	assert(a);
	child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
			child++;
		if (a[child]>a[parent])
		{
			Swap(a + child, a + parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDataType*a, int n, int child)
{
	int parent;
	assert(a);
	parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(a + parent, a + child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i;
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(n*sizeof(HPDataType));
	hp->_size = n;
	hp->_capacity = n;
	//录入
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	//调整
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
static int Log(int n)
{
	int i = 0;
	while (n >= 2)
	{
		i++;
		n /= 2;
	}
	return i;
}
void HeapPrint(Heap* hp)
{
	int i, j, n, p = 1;
	assert(hp);
	n = Log(hp->_size);
	for (i = 0; i < hp->_size; i++)
	{
		if (i == pow(2, p)-1)
		{
			for (j = 0; j <= n*2-1;j++)
				printf("\n");
			p++;
			n--;
		}
		for (j = 0; j < pow(2, n) - 1; j++)
		{
			printf("   ");
		}
		printf("%2d ",hp->_a[i]);
		for (j = 0; j < pow(2, n) - 1; j++)
		{
			printf("   ");
		}
		printf("   ");
	}
	printf("\n\n\n");
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size = hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
		if (hp->_a == NULL)
		{
			perror("realloc");
		}
	}
	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size, hp->_size-1);
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap((hp->_a), (hp->_a) + (hp->_size--) - 1);
	AdjustDown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size != 0;
}

// 不要直接调Heap
void HeapSort(HPDataType* a, int n)
{
	int i,size;
	assert(a);
	size = n;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	for (i = 0; i < n - 1; i++)
	{
		Swap(a, a + size - 1);
		size--;
		AdjustDown(a, size, 0);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		if (i < n - 1)
			printf("<");
	}
	printf("\n");
}
void TopK(HPDataType* a, int n, int k)
{
	Heap h;
	int i;
	assert(a);
	for (i = 0; i < k; i++)
	{
		a[i] = -a[i];
	}
	HeapInit(&h, a, k);
	for (; i < n; i++)
	{
		if (-a[i] < HeapTop(&h))
		{
			h._a[0] = -a[i];
			AdjustDown(h._a, k, 0);
		}
	}
	for (i = 0; i < k; i++)
	{
		h._a[i] = -h._a[i];
	}
	HeapSort(h._a, k);
}
void TestHeap()
{
	Heap h;
	int i = 0;
	HPDataType NArray[1000];
	HPDataType a[30] = { 15, 16, 14, 11, 12, 13, 19, 17, 18, 10, 25, 26, 24, 21, 22, 23, 29, 27, 28, 20, 41, 42, 43, 44, 45, 46, 47, 48, 49, 40};
	HeapInit(&h, a, 30);
	HeapPrint(&h);
	HeapPush(&h, 99);
	HeapPrint(&h);
	HeapPop(&h);
	HeapPrint(&h);
	HeapSort(a, 30);


	srand(time(0));
	for (i = 0; i < 1000; ++i)
	{
		NArray[i] = rand() % 10000;
	}

	NArray[30] = 10001;
	NArray[350] = 10002;
	NArray[999] = 10003;
	NArray[158] = 10004;
	NArray[334] = 10005;

	TopK(NArray, 1000, 5);
}