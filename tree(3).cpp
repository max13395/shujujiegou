#include <stdio.h>
#include<stdlib.h>//二叉查找树不能插入重复元素
typedef int E;
struct searchtree
{
	E element;
	searchtree* left;
	searchtree* right;
};
typedef searchtree* node;
void show(node root)
{
	if (root == NULL)
	{
		return;
	}
	show(root->left);
	printf("%d\n", root->element);
	show(root->right);
}
node creatnode(E element)
{
	node root = (node)malloc(sizeof(searchtree));
	root->left = root->right = NULL;
	root->element = element;
	return root;
}
node insert(node root,E element)
{
	if (root)
	{
		if (root->element > element)
		{
			root->left = insert(root->left, element);
		}
		else
		{
			root->right = insert(root->right, element);
		}
	}
	else
	{
		root = creatnode(element);
	}
	return root;
}
node find(node root, E element)
{
	while (root != NULL)
	{
		if (element == root->element)
			return root;
		else if (element < root->element)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	return NULL;
}
node findmax(node root)
{
	while (root&&root->right)
	{
		root = root->right;
	}
	return root;
}
node erase(node root,E key)
{
	if (root == NULL) return NULL;
	else
	{
		if (root->element > key)
		{
			root->left = erase(root->left, key);

		}
		else if (root->element < key)
		{
			root->right = erase(root->right, key);

		}
		else
		{
			if (root->left && root->right)
			{
				node max = findmax(root->left);
				root->element = max->element;
				root->left = erase(root->left, max->element);
			}
			else
			{
				node temp = root;
				if (root->right)
				{
					root = root->right;
				}
				else
				{
					root = root->left;
				}
				free(temp);
			}
		}
	}
	return root;
}
int main()
{
	node root;
	root = creatnode(3);
	insert(root, 1);
	insert(root, 2);
	show(root);
	erase(root, 3);
	show(root);
	return 0;
}

