#include "Stack.h"
void StackPushM(StackM* ps, DataType x)
{
	assert(ps);
	StackPopM(&ps->data, x);
	if (StackEmpty(&ps->min) == 0||StackTop(&ps->min)>=x)
		StackPopM(&ps->min, x);
}
void StackPopM(StackM* ps)
{
	if (StackTop(&ps->data) == StackTop(&ps->min))
		StackPop(&ps->min);
	StackPop(&ps->data);
}
DataType StackMin(StackM* ps)
{
	return StackTop(&ps->min);
}