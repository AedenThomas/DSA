#include <stdio.h>
#include <stdlib.h>

// Write a program to construct a Binary search tree and perform inorder, preorder, postorder traversals

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// A utility function to do postorder traversal of BST
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// insert a node in the binary search tree
void create(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (data <= (*root)->data) //
    {
        create(&((*root)->left), data);
    }
    else
    {
        create(&((*root)->right), data);
    }
}

// Main function to test above functions
int main()
{
    struct node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            create(&root, data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}