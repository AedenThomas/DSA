//reverse a linked list using recursion

#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int reverse(struct node *head)
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
    {
        printf("%d", head->data);
        return 0;
    }
    reverse(head->next);
    printf("%d", head->data);
}