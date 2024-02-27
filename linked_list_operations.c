
#include <stdio.h>
#include <stdlib.h>
// Node creation
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insertRear(NODE first)
{
    NODE temp, cur;
    int item;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n Unable to allocate memory...\n");
        return first;
    }
    printf("\nEnter an element to be inserted: ");
    scanf("%d", &item);
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        first = temp;
    else
    {
        cur = first;

        while (cur->link != NULL)
            cur = cur->link;
        cur->link = temp;
    }
    return first;
}
// Display the contents of the linked list
void display(NODE first)
{
    NODE cur;
    if (first == NULL)
        printf("\nList is empty, no elements to display\n");
    else
    {
        cur = first;
        printf("\nElements in the linked list are : ");
        while (cur != NULL)
        {
            printf("%d\t", cur->info);
            cur = cur->link;
        }
    }
}

NODE concat(NODE first, NODE second)
{
    NODE cur;
    cur = first;
    // if (first == NULL)
    // {
    //     if (second == NULL)
    //         return first;
    //     else
    //         return second;
    // }
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = second;
    return first;
}
int main()
{
    NODE first = NULL, second = NULL;
    int choice;

    printf("\n********* Creation of SLL - 1 and SLL - 2 *********\n");
    while (1)
    {

        printf("\n1. Insert to SLL - 1\n2. Insert to SLL - 2\n3. Display SLL - 1\n4. Display SLL - 2\n5. Concatenate SLL - 1 and SLL - 2\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insertRear(first);
            break;
        case 2:
            second = insertRear(second);
            break;
        case 3:
            display(first);
            break;
        case 4:
            display(second);
            break;
        case 5:
            first = concat(first, second);
            display(first);
            second = NULL;
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong choice, please try again\n");
        }
    }
}