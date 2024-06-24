#include<stdio.h>
#include<stdlib.h>
typedef int E;
struct Stack
{
	E* arry=NULL;
	int capacity=0;
	int top=-1;
};
typedef Stack* ArryStack;
bool initStack(ArryStack st)
{
	st->arry =(E*) malloc(sizeof(E) * 10);
	if (st->arry == NULL) return false;
	st->capacity = 10;
	return true;
}
bool pushStack(ArryStack st,E element)
{
	if (st->top == (st->capacity - 1))
	{
		E* newarry = (E*)realloc(st->arry, sizeof(E) * (st->capacity + 5));
		if (newarry == NULL) return false;
		st->capacity = st->capacity + 5;
		st->arry = newarry;

	}
	st->arry[st->top + 1] = element;
	st->top++;
	return true;
}
bool Stackempty(ArryStack st)
{
	if (st->top == -1)return true;
	else return false;
}
E popStack(ArryStack st)
{
	E t = st->arry[st->top];
	st->top = st->top - 1;
	return t;
}
E topStack(ArryStack st)
{
	return st->arry[st->top];
}
int main()
{
	Stack st;
	initStack(&st);
	printf("%d\n", st.capacity);
	for (int i = 1; i <= 15; i++)
	{
		pushStack(&st, i * 10);
		printf("%d\n", topStack(&st));
	}
	return 0;
}

