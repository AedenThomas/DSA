// A node in a doubly linked list contains following information – Student name, USN and CGPA. 
// Define a structure to represent the same and develop C functions to perform the following operations on the list:
// i) Search for a student with specified USN and update his/her CGPA.
// ii) Delete the student with specified USN.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    char usn[10];
    float cgpa;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

void searchAndUpdate(struct node *head, char usn[10], float cgpa)
{
    struct node *temp=head;
    while (temp != NULL)
    {
        if (strcmp(temp->usn, usn) == 0)
        {
            temp->cgpa = cgpa;
            return;
        }
        temp = temp->next;
    }
}
void deleteNode(struct node *head, char usn[10])
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->usn, usn) == 0)
        {
            if (temp == head)
            {
                head = head->next;
                head->prev = NULL;
                free(temp);
                return;
            }
            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
}


void insert(char name[20], char usn[10], float cgpa)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->usn, usn);
    newnode->cgpa = cgpa;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

int main()
{
    insert("A", "1", 1.0);
    insert("B", "2", 2.0);
    insert("C", "3", 3.0);
    insert("D", "4", 4.0);
    searchAndUpdate(head, "3", 5.0);
    deleteNode(head, "2");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%s %s %f\n", temp->name, temp->usn, temp->cgpa);
        temp = temp->next;
    }
    
}