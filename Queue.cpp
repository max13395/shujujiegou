#include<stdlib.h>
#include <stdio.h>
typedef int E;
struct vector_queue
{
	E* arry=NULL;
	int front=0;
	int rear=0;
	int capacity = 0;
};
typedef vector_queue* queue;
bool initvector_queue(queue qu,int n)
{
	qu->arry = (E*)malloc(sizeof(E) * n);
	if (qu->arry == NULL) return false;
	qu->capacity = n;
	return true;
}
bool pushqueue(queue qu,E element)
{
	if (qu->capacity == qu->rear) return false;
	qu->arry[qu->rear] = element;
	qu->rear = qu->rear + 1;
	return true;
}
bool empty(queue qu)
{
	return qu->front == qu->rear;
}
int sizequeue(queue qu)
{
	return (qu->rear - qu->front);
}
E topqueue(queue qu)
{
	return qu->arry[qu->rear-1];
}
void popqueue(queue qu)
{
	if (empty(qu))
	{
		printf("empty");
		return;
	}
	else if (sizequeue(qu) == 1)
	{
		qu->front = qu->rear = 0;
		return;
	}
	else
	{
		for (int i = qu->front; i < qu->rear - 1; i++)
			qu->arry[i] = qu->arry[i + 1];
		qu->rear = qu->rear - 1;
		return;
	}
}
int main()
{
	vector_queue qu;
	initvector_queue(&qu, 10);
	printf("%d\n", qu.capacity);
	if (empty(&qu))
	{
		printf("yes\n");
	}
	for (int i = 1; i <= 5; i++)
	pushqueue(&qu, i);
	printf("%d\n", topqueue(&qu));
	popqueue(&qu);
	printf("%d\n", qu.arry[qu.front]);
	while (!empty(&qu))
	{
		printf("%d ", qu.arry[qu.front]);
		popqueue(&qu);
	}
	return 0;
}

