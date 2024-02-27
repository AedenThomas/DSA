// Do following operations on a linked list
// Sort in ascending order
// Insert a value at a given position
// Print the data in the list in reverse order
// Insert at the end
// Search for a value
// Delete rear element from single linked list
// Delete element at the given position
// Delete alternate nodes in a single linked list
// print middle element
// reverse the same without creating new list.
// sum of nodes with even data and sum of nodes with odd data
// count nodes with prime values and delete the first prime node.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

struct node *firstnode;
void sortAscending(struct node *firstnode);
void insertAtPosition(struct node *firstnode, int position, int num);
void printReverse(struct node *firstnode);
void insertAtEnd(struct node *firstnode, int num);
void search(struct node *firstnode, int num);
void deleteRear(struct node *firstnode);
void deletePosition(struct node *firstnode, int position);
void deleteAlternate(struct node *firstnode);
void printMiddle(struct node *firstnode);
void reverse(struct node *firstnode);
void sumEvenOdd(struct node *firstnode);
void primeCount(struct node *firstnode);
void deletePrime(struct node *firstnode);

void display(struct node *firstnode)
{
    struct node *tmp;
    tmp = firstnode;
    while (tmp != NULL)
    {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

void sortAscending(struct node *firstnode)
{
    struct node *curr = firstnode;
    int temp;
    if (firstnode == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (curr != NULL)
    {
        struct node *next = curr->next;
        while (next != NULL)
        {
            if (curr->num > next->num)
            {
                temp = curr->num;
                curr->num = next->num;
                next->num = temp;
            }
            next = next->next;
        }
        curr = curr->next;
    }
}

void insertAtPosition(struct node *firstnode, int position, int num)
{
    struct node *temp, *newNode;
    int i;
    temp = firstnode;
    for (i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = num;
    newNode->next = temp->next;
    temp->next = newNode;
}

void printReverse(struct node *firstnode)
{
    struct node *temp;
    temp = firstnode;

    if (temp == NULL)
        return;

    printReverse(temp->next);

    printf("%d ", temp->num);
}

void insertAtEnd(struct node *firstnode, int num)
{
    struct node *temp, *newNode;
    temp = firstnode;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = num;
    newNode->next = NULL;
    temp->next = newNode;
}


void search(struct node *firstnode, int num)
{
    struct node *temp;
    temp = firstnode;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->num == num)
        {
            printf("%d found at position %d\n", temp->num, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("%d not found\n", num);
}


void deleteRear(struct node *firstnode)
{
    struct node *temp, *temp1;
    temp = firstnode;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
}

void deletePosition(struct node *firstnode, int position)
{
    struct node *temp, *temp1;
    int i;
    temp = firstnode;
    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

void deleteAlternate(struct node *firstnode)
{
    struct node *temp = firstnode;

    if (temp == NULL)
        return;

    struct node *toBeDeleted = temp->next;

    if (toBeDeleted == NULL)
        return;

    temp->next = toBeDeleted->next;
    free(toBeDeleted);
    deleteAlternate(temp->next);
}

void printMiddle(struct node *firstnode)
{
    struct node *temp, *temp1;
    int count = 0;
    temp = firstnode;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = firstnode;
    for (int i = 0; i < count / 2; i++)
    {
        temp = temp->next;
    }
    printf("%d\n", temp->num);
}

void reverse(struct node *firstnode)
{
    struct node *prev = NULL, *next = NULL, *curr = firstnode;

    while (curr != NULL)
    {
        // Store next
        next = curr->next;
        // Reverse current node's pointer
        curr->next = prev;
        // Move pointers one position ahead.
        prev = curr;
        curr = next;
    }
    firstnode = prev;
    display(firstnode);
}

void sumEvenOdd(struct node *firstnode)
{
    struct node *temp;
    int evenSum = 0, oddSum = 0;
    temp = firstnode;
    while (temp != NULL)
    {
        if (temp->num % 2 == 0)
        {
            evenSum += temp->num;
        }
        else
        {
            oddSum += temp->num;
        }
        temp = temp->next;
    }
    printf("Even sum: %d\n", evenSum);
    printf("Odd sum: %d\n", oddSum);
}

void primeCount(struct node *firstnode)
{
    struct node *temp;
    int count = 0;
    temp = firstnode;
    while (temp->next != NULL)
    {
        if (temp->num % 2 != 0 && temp->num % 3 != 0 && temp->num % 5 != 0 && temp->num % 7 != 0)
        {
            count++;
        }
        temp = temp->next;
    }
    printf("Prime count: %d\n", count);
}

void deletePrime(struct node *firstnode)
{
    struct node *temp, *temp1;
    temp = firstnode;
    while (temp->next != NULL)
    {
        if (temp->num % 2 != 0 && temp->num % 3 != 0 && temp->num % 5 != 0 && temp->num % 7 != 0)
        {
            temp1 = temp;
            temp = temp->next;
            temp1->next = temp->next;
            free(temp);
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{

    int choice, num, position, limit;
    struct node *firstnode;
    firstnode = (struct node *)malloc(sizeof(struct node));
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &limit);
    printf("Enter data for first node: ");
    scanf("%d", &num);
    firstnode->num = num;
    firstnode->next = NULL;
    printf("\n");
    for (int i = 1; i < limit; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &num);
        insertAtEnd(firstnode, num);
        printf("\n");
    }

    while (1)
    {
        printf("1. Sort in ascending order\n2. Insert a value at a given position\n3. Print the data in the list in reverse order\n4. Insert at the end\n5. Search for a value\n6. Delete rear element from single linked list\n7. Delete element at the given position\n8. Delete alternate nodes in a single linked list\n9. print middle element\n10. reverse the same without creating new list.\n11. sum of nodes with even data and sum of nodes with odd data\n12. count nodes with prime values and delete the first prime node.\n13. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sortAscending(firstnode);
            break;
        case 2:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(firstnode, position, num);
            break;
        case 3:
            printReverse(firstnode);
            break;
        case 4:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            insertAtEnd(firstnode, num);
            break;
        case 5:
            printf("Enter the number to be searched: ");
            scanf("%d", &num);
            search(firstnode, num);
            break;
        case 6:
            deleteRear(firstnode);
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &position);
            deletePosition(firstnode, position);
            break;
        case 8:
            deleteAlternate(firstnode);
            break;
        case 9:
            printMiddle(firstnode);
            break;
        case 10:
            reverse(firstnode);
            break;
        case 11:
            sumEvenOdd(firstnode);
            break;
        case 12:
            primeCount(firstnode);
            break;
        case 13:
            display(firstnode);
            break;
        case 14:
            deletePrime(firstnode);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}