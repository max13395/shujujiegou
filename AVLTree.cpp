#include <stdio.h>
#include<stdlib.h>
typedef int E;
struct AVLTree
{
    E element;
    AVLTree* left;
    AVLTree* right;
    int height;
};
typedef AVLTree* node;
node createnode(E key)
{
    node root = (node)malloc(sizeof(AVLTree));
    root->left = root->right = NULL;
    root->height = key;
    root->height = 1;
    return root;

}
int max(int a,int b)
{
    return a > b ? a : b;
}//一下有四种处理方法分别是LL,RR,RL,LR,问题
int gethigh(node root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
node leftrotation(node root)//传入老根，返回新根
{
    node newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    newroot->height = max(gethigh(newroot->left), gethigh(newroot->right)) + 1;
    root->height= max(gethigh(root->left), gethigh(root->right)) + 1;
    return newroot;
}
node rightrotation(node root)//传入老根，返回新根
{
    node newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    newroot->height = max(gethigh(newroot->left), gethigh(newroot->right)) + 1;
    root->height = max(gethigh(root->left), gethigh(root->right)) + 1;
    return newroot;
}
node leftrightrotation(node root)
{
    root->left = leftrotation(root->left);
    return rightrotation(root);
}
node rightleftrotation(node root)
{
    root->right = rightrotation(root->left);
    return leftrotation(root);
}
node insert(node root,E key)
{
    if (root == NULL)
    {
        root = createnode(key);
    }
    else
    {
        if (key < root->element)
        {
            root->left = insert(root->left, key);
            if (gethigh(root->left) - gethigh(root->right) > 1)
            {
                if (root->left->element > key)
                {
                    root = rightrotation(root);
                }
                else
                {
                    root = leftrightrotation(root);

                }
            }

        }
        else
        {
            root->right = insert(root->right, key);
            if (gethigh(root->right) - gethigh(root->left) > 1)
            {
                if (root->right->element < key)
                {
                    root = leftrotation(root);
                }
                else
                {
                    root = rightleftrotation(root);
                }
            }

        }
    }
    root->height = max(gethigh(root->left), gethigh(root->right)) + 1;
    return root;

}

int main()
{
    
}
