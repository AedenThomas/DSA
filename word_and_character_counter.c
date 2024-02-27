#include <stdio.h>
void read(char *p, int size)
{
    int countW = 0, countC = 0;
    while (*p != '\0')
    {
        if (*p == ' ')
            countW++;
        else
            countC++;
        p++;
    };
    countW++;
    printf("Number of words is %d", countW);
    printf("\nNumber of characters (excluding space) is %d\n", countC);
}

int main()
{
    char input[50];
    printf("Enter the string: ");
    gets(input);
    read(input, 50);
}