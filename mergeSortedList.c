#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

struct node *createNNode(int n, struct node *head)
{
    if (n != 0)
    {
        // printf("Enter -1 to stop");
        int stopOption;

        struct node *newNode, *tmp;
        int num, i;
        head = (struct node *)malloc(sizeof(struct node));
        tmp = (struct node *)malloc(sizeof(struct node));

        if (head == NULL)
            printf(" Memory can not be allocated.");
        else
        {
            printf("Enter the num for node 1 : ");
            scanf("%d", &num);
            head->num = num;
            head->next = NULL;
            tmp = head;

            for (i = 2; i <= n; i++)
            // for (i = 2; num!=-1; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if (newNode == NULL)
                {
                    printf("Memory can not be allocated.");
                    break;
                }
                else
                {
                    printf("Enter the num for node %d : ", i);
                    scanf(" %d", &num);
                    // if (num != -1)
                    // {
                    newNode->num = num;
                    newNode->next = NULL;

                    tmp->next = newNode;
                    tmp = tmp->next;
                    // }
                }
            }
        }
    }

    return head;
}

void output(struct node *head)
{
    struct node *tmp;
    if (head == NULL)
        printf("List is empty.");
    else
    {
        tmp = head;
        int i = 1;
        while (tmp != NULL)
        {
            printf("The num in Node No.%d = %d\n", i, tmp->num);
            tmp = tmp->next;
            i++;
        }
    }
}

struct node *MergeLists(struct node *headA, struct node *headB)
{
    struct node *prev, *temp, *result;

    if (headA == NULL)
    {
        if (headB == NULL)
        {
            return headA;
        }
        else
        {
            return headB;
        }
    }

    if (headB == NULL)
    {
        return headA;
    }

    if (headA->next == NULL && headB->next == NULL)
    {
        if (headA->num > headB->num)
        {
            headB->next = headA;
            return headB;
        }
        else
        {
            headA->next = headB;
            return headA;
        }
    }

    if (headB->num >= headA->num)
    {
        result = headA;

        while (headB != NULL)
        {
            while (headB->num >= headA->num && headA->next != NULL)
            {
                prev = headA;
                headA = headA->next;
            }

            if (headA->next == NULL)
            {
                if (headB->num >= headA->num)
                {
                    headA->next = headB;
                    return result;
                }
            }

            prev->next = headB;
            temp = headB->next;
            headB->next = headA;
            headB = temp;
        }
    }
    else
    {
        result = headB;

        while (headA != NULL)
        {
            while (headA->num >= headB->num && headB->next != NULL)
            {
                prev = headB;
                headB = headB->next;
            }

            if (headB->next == NULL)
            {
                if (headA->num >= headB->num)
                {
                    headB->next = headA;
                    return result;
                }
            }

            prev->next = headA;
            temp = headA->next;
            headA->next = headB;
            headA = temp;
        }
    }

    return result;
}

int main()
{
    int n, num, opt, pos;
    struct node *firstnodeA = NULL, *firstnodeB = NULL, *mergedList = NULL;
    while (1)
    {
        printf("\n1. Create 2 lists");
        printf("\n2. Display lists");
        printf("\n3. Merge and sort lists");
        printf("\n4. Exit\n");

        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("\nHow many nodes do you want in the first list? ");
            scanf("%d", &n);
            firstnodeA = createNNode(n, firstnodeA);

            printf("\n\nHow many nodes do you want in the second list? ");
            scanf("%d", &n);
            firstnodeB = createNNode(n, firstnodeB);
            break;
        case 2:
            printf("\nFirst list:\n");
            output(firstnodeA);
            printf("\nSecond list:\n");
            output(firstnodeB);
            break;
        case 3:
            mergedList = MergeLists(firstnodeA, firstnodeB);
            printf("\nMerged list:\n");
            output(mergedList);
            break;
        case 4:
            exit(0);
            break;
        }
    }

    return 0;
}
