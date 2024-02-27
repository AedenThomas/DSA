#include <stdio.h>
#include <stdlib.h>
//queue using linked list
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nMemory not allocated");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    int n;
    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the number: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            break;
        }
    }
    return 0;
}