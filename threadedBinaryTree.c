// Implement single Threaded Binary Tree 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *rightThreaded;
};

void insert(struct node **root, int data)
{
    if(*root == NULL)
    {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->rightThreaded = NULL;
    }
    else if(data <= (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

int main()
{
    struct node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);

}