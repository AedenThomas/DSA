// Write C program to check whether the given string is palindrome using double linked list (Each character in string is stored in a node).

#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

void checkPalindrome()
{
    struct node *right, *left;
    right = head;
    left = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    //now right is at the last node
    while (left != right)
    {
        if (left->data != right->data)
        {
            printf("Not a palindrome\n");
            return;
        }
        left = left->next;
        right = right->prev;
    }
    printf("Palindrome\n");
}


void insert(char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
}

int main()
{
    struct node *head = NULL;
    insert('a');
    insert('e');
    insert('d');
    insert('e');
    insert('a');
    checkPalindrome();
   
}