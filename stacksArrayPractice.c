#include<stdio.h>
int stack[100], n, top=-1, x, i;

void push()
{
    int element;
    if (top>=n-1)
    {
        printf("Stack overflow!");
    }
    else 
    {
        printf("Enter the value to be pushed: ");
        scanf("%d", &element);
        top++;
        stack[top]=element;
    }
}

void pop()
{
    if (top<=-1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("The popped element is %d ", stack[top]);
        top--;
    }
}

void display()
{
    
}
int main()
{
    int option, size;

    printf("Enter size of stack: ");
    scanf("%d", &size);

    printf("\1. Push\n");
    printf("\2. Pop\n");
    printf("\3. Display\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
    
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nInvalid option");
    }
    return 0;
}