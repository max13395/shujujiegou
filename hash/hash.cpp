#include <stdio.h>
#include<stdlib.h>//hash直接寻址
#define size 9
struct  element
{
	int key;

};
typedef element* E;
struct hashtable
{
	E* table;
};
typedef hashtable* hash;
int gethash(E element)
{
	return ((element->key) % size);
}
bool find(hash t,E element)
{
	int hashcode = gethash(element);
	if (!t->table[hashcode])return false;
	return t->table[hashcode]->key == element->key;
}
bool inihash(hash h)
{
	h->table = (E*)malloc(sizeof(element) * size);
	if (h->table == NULL) return false;
	return true;
}
void insert(hash h, E element)
{
	int hashcode = gethash(element);
	h->table[hashcode] = element;
}
E create_element(int key)
{
	E node = (E)malloc(sizeof(element));
	if (node == NULL)return NULL;
	node->key = key;
	return node;
}
int main()
{
	hashtable ha ;
	inihash(&ha);
	E dot1 = create_element(10);
	E dot2 = create_element(9);
	E dot3 = create_element(28);
	E dot4 = create_element(7);
	insert(&ha, dot1);
	insert(&ha, dot2);
	insert(&ha, dot3);
	insert(&ha, dot4);
	printf("%d", ha.table[1]->key);



}

