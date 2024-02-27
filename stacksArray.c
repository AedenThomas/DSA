#include <stdio.h>
int Stack[100], choice, n, top, x, i;
void push()
{
    if (top >= n - 1)
    {
        printf("\nStack is over flow");
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        Stack[top] = x;
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("\nStack is under flow");
    }
    else
    {
        printf("\nThe popped elements is %d", Stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\nThe elements in Stack\n");
        for (i = top; i >= 0; i--)
            printf("\n%d", Stack[i]);
    }
    else
    {
        printf("\n The Stack is empty");
    }
}
int main()
{

    top = -1;
    printf("\nEnter the size of Stack:");
    scanf("%d", &n);
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            printf("\nPlease Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}