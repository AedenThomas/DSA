#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

void display()
{
    node *ptr;
    ptr = head;
    int i = 1;
    if (head == NULL)
    {
        printf("List not created\n");
    }
    printf("%d", ptr->data);
    while (ptr->next != NULL)
    {
        printf(" ----> %d", ptr->next->data);
        i++;
        ptr = ptr->next;
    }
}

void displayRev() // Display list in reverse order
{
    node *ptr;
    ptr = head->next;
    int i = 1;
    if (head == NULL)
    {
        printf("List not created\n");
    }
    printf(" ----> %d", ptr->data);
    while (ptr->next != NULL)
    {
        printf(" ----> %d", ptr->next->data);
        i++;
        ptr = ptr->next;
    }
}

void createNode(int n)
{
    node *temp;
    head = (node *)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Node Creation Failed... Try again...");
    }
    else
    {
        head->data = 1;
        head->next = NULL;
        temp = head;
        if (n > 1)
        {
            node *newNode;
            for (int i = 2; i <= n; i++)
            {
                newNode = (node *)malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node Creation Failed... Try again...");
                }
                else
                {
                    newNode->data = i;
                    temp->next = newNode;
                    temp = temp->next;
                    newNode->next = NULL;
                }
            }
        }
    }
}

static void reverse()
{
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

void path()
{
    display();    // Display list in forward order
    reverse();    // Reverse the list
    displayRev(); // Display list in reverse order
    reverse();    // Reverse the list again to get the original list
    displayRev(); // Display list in reverse order
}

int main()
{
    int n, d;
    printf("----------------------------------------------------------\n");
    printf("Enter the no. of stations you want: ");
    scanf("%d", &n);
    printf("Enter the distance between each of the stations: ");
    scanf("%d", &d);
    if (n <= 0)
    {
        printf("No node created... Try again...");
    }
    else if (n > 0)
    {
        createNode(n);
        printf("----------------------------------------------------------\n");
    }

    clock_t start = clock();
    
    
    path();
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("Time taken to execute the program is %f seconds", time_taken);
    printf("\n----------------------------------------------------------\n");
    printf("Hence we can observe that the toal no. of path traversals in direct approach is 3(n-1) i.e. %d for %d stations\nHence the distance is: %d\n", 3 * (n - 1), n, 3 * (n - 1) * d);
    return 0;
}