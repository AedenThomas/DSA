#include <stdio.h>

int fib(int n)
{
    if (n == 1 || n == 0)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int f, n;
    printf("Enter the number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        f = fib(i);
        printf("%d ", f);
    }
    return 1;
}