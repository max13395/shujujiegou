#include<stdio.h>
#include<stdlib.h>
typedef int E;
struct doubleListNode
{
	E element;
	doubleListNode* pre;
	doubleListNode* next;
};
typedef  doubleListNode* dnode;
void initList(dnode head)
{
	head->next = head->pre = NULL;
}
bool insertList(dnode head,E element,int index)
{
	if (index < 1) return false;
	while (--index)
	{
		head = head->next;
		if (head == NULL) return false;
	}
	dnode p = (dnode)malloc(sizeof(doubleListNode));
	p->element = element;
	p->pre = head;
	p->next = head->next;
	head->next->pre = p;
	head->next = p;
	return true;

}
void printList(dnode head)
{
	while (head->next)
	{
		head = head->next;
		printf("%d\n", head->element);
	}
}
int main()
{
	doubleListNode head;
	initList(&head);
	for (int i = 1; i <= 5; i++)
	{
		insertList(&head, i * 100, i);
	}
	printList(&head);
	return 0;
}