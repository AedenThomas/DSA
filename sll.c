// A singly linked list containing both positive numbers and negative
// numbers is given. Use this linked list and write a C routine to create two
// singly linked lists (with header nodes), one containing all positive
// numbers and the other containing negative numbers. Print the resulting
// lists.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void seperateIntoTwoLinkedList(struct node *head)
{
    // even and odd linked list
    struct node *evenHead = NULL;
    struct node *oddHead = NULL;
    struct node *even = NULL;
    struct node *odd = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0) //even
        {
            if (evenHead == NULL) //first even number
            {
                evenHead = temp;
                even = temp;
            }
            else
            {
                even->next = temp;
                even = even->next;
            }
        }
        else //odd
        {
            if (oddHead == NULL) //first odd number
            {
                oddHead = temp;
                odd = temp;
            }
            else
            {
                odd->next = temp;
                odd = odd->next;
            }
        }
        temp = temp->next;
    }
    even->next = NULL;
    odd->next = NULL;
    printf("Even Linked List: ");
    while (evenHead != NULL)
    {
        printf("%d ", evenHead->data);
        evenHead = evenHead->next;
    }
    printf("\n");
    printf("Odd Linked List: ");
    while (oddHead != NULL)
    {
        printf("%d ", oddHead->data);
        oddHead = oddHead->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int i;
    for (i = 0; i < 10; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    seperateIntoTwoLinkedList(head);
    return 0;
}