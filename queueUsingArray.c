//Develop a program to demonstrate Queue operations(using array)
// Enqueue
// Dequeue
// IsFull
// IsEmpty
// Display

//haven't used GLOBAL variables, instead passed variables as pointers in the functions

#include <stdio.h>
#include <stdlib.h>

int isFull(int queue[], int size, int front, int rear)
{
    if (rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(int queue[], int size, int front, int rear)
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int queue[], int size, int *front, int *rear)
{
    int item;
    if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else if (*rear == size - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        *rear = *rear + 1;
    }
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    queue[*rear] = item;
}
void dequeue(int queue[], int size, int *front, int *rear)
{
    int item;
    if (*front == -1 && *rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        item = queue[*front];
        if (*front == *rear)
        {
            *front = -1;
            *rear = -1;
        }
        else
        {
            *front = *front + 1;
        }
        printf("The deleted item is %d\n", item);
    }
}
void display(int queue[], int size, int front, int rear)
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue is:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int size, choice;
    printf("Enter the size of the queue");
    scanf("%d", &size);
    int queue[size];
    int front = -1;
    int rear = -1;
    int item;
    int i;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsFull\n");
        printf("4. IsEmpty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(queue, size, &front, &rear);
            break;
        case 2:
            dequeue(queue, size, &front, &rear);
            break;
        case 3:
            if (isFull(queue, size, front, rear))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;
        case 4:
            if (isEmpty(queue, size, front, rear))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            display(queue, size, front, rear);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
