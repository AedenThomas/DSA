#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
//FUnction to delete first node
void deleteFirstNode()
{
    struct node *temp = head;
    head = (head)->next;
    (head)->prev = NULL;
    //should we put temp.next = NULL?
    free(temp);
}

//function to delete last node
void deleteLastNode()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

//function to delete node based on data
void deleteNode(int data)
{
    struct node *temp = head;

    while (temp->data != data)
    {
        temp = temp->next;
    }
    //if data is first node
    if (temp == head)
    {
        deleteFirstNode();
        return;
    }
    //if data is last node
    if (temp->next == NULL)
    {
        deleteLastNode();
        return;
    }
    //if data is in between
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

//function to delete middle node by going to the last node and coming back to the middle node
void deleteMiddleNode()
{
    struct node *firstNode = head;
    struct node *lastNode = head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    //lastNode is the last node

    //now iterate from firstNode to lastNode and from lastNode to firstNode to find the middle node and delete it
    while (firstNode != lastNode)
    {
        firstNode = firstNode->next;
        //if there are even number of nodes
        lastNode = lastNode->prev;
    }
    //firstNode is the middle node
    firstNode->prev->next = firstNode->next;
    firstNode->next->prev = firstNode->prev;
    free(firstNode);
}

//function to delete middle node by having two pointers and iterating through the list
// slow_ptr, and fast_ptr. Both pointers start from the head of list. When fast_ptr reaches the end, slow_ptr reaches middle
// node.
void deleteMiddleNode2()
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    while (fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next;
        if (fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
    }
    slow_ptr->prev->next = slow_ptr->next;
    slow_ptr->next->prev = slow_ptr->prev;
    free(slow_ptr);
}

// Function to create a new node
void insert(int data)
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
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}

//Function to insert before a given value
void insertBefore(int data, int value)
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
    struct node *curr = head;
    while (curr->data != value)
    {
        curr = curr->next;
    }
    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void sortDoubleLinkedList()
{
    struct node *temp = head; //
    while (curr != NULL)
    {
        struct node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data > curr->data)
            {
                int tempData = curr->data;
                curr->data = curr->data;
                temp->data = tempData;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

void insertIntoSortList(data)
{
    // insert into sorted list and keep the list sorted
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data > data)
        {
            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;
            return;
        }
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}

void printInReverse()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    int n, data, dataToBeInserted;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for node %d : ", i + 1);
        scanf("%d", &data);
        insert(data);
    }

    //menu driven program
    int choice;
    while (1)
    {
        printf("\n1. Delete first node\n2. Delete last node\n3. Delete node\n4. Delete middle node \n5. Insert before\n6. Display\n7. Sort the list\n8. Insert into sorted list\n9. Print in reverse\n10. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deleteFirstNode();
            break;
        case 2:
            deleteLastNode();
            break;
        case 3:
            printf("Enter the data to be deleted: ");
            scanf("%d", &data);
            deleteNode(data);
            break;
        case 4:
            deleteMiddleNode();
            break;
        case 5:
            printf("Enter the data to be inserted: ");
            scanf("%d", &dataToBeInserted);
            printf("Enter the value before which data is to be inserted: ");
            scanf("%d", &data);
            insertBefore(dataToBeInserted, data);
            break;
        case 6:
            display();
            break;
        case 7:
            sortDoubleLinkedList();
            break;
        case 8:
            printf("Enter the data to be inserted: ");
            scanf("%d", &dataToBeInserted);
            insertIntoSortList(dataToBeInserted);
            break;
        case 9:
            printInReverse();
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
