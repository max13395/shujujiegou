#include <stdio.h>
#include<stdlib.h>  
typedef int E;
struct  treenode
{
    E element;
    treenode* left;
    treenode* right;
};
typedef treenode* node;
void inittree(node root,E element)
{
    root->left = NULL;
    root->right = NULL;
    root->element = element;
}
void rightinsert(node root,E element)
{
    if (root->right != NULL)
    {
        printf("right full");
        return;
    }
    node t = (node)malloc(sizeof(treenode));
    if (t == NULL)
    {
        printf("There is no enough capacity");
        return;
    }
    inittree(t, element);
    root->right = t;
}
void leftinsert(node root,E element)
{
    if (root->left != NULL)
    {
        printf("left full");
        return;
    }
    node t=(node)malloc(sizeof(treenode));
    if (t == NULL)
    {
        printf("There is no enough capacity");
        return;
    }
    inittree(t, element);
    root->left = t;


}
void preorder(node root)
{
    if (root == NULL) return ;
    printf("%d\n", root->element);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->element);
    inorder(root->right);
}

int main()
{
    treenode root;
    inittree(&root, 2);
    printf("%d\n", root.element);
    leftinsert(&root, 3);
    preorder(&root);
    return 0;

}

