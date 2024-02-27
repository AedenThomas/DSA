#include <stdio.h>

//prime using recursion

int primeno(int num, int i)
{
    if (i == 1)
    {
        //number is prime
        return 1;
    }
    else
    {
        if (num % i == 0)
        {
            //number is not prime
            return 0;
        }
        else
        {
            //decrement second parameter and check again
            return primeno(num, i - 1);
        }
    }
}

// teacher's method
// int primeno(int num, int i)
// {
//     if (num == 1 | num == i)
//         return 1;
//     if (num % i == 0)
//         return 0;
//     return primeno(num, i + 1);
// }

int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);

    if (primeno(n, n / 2) == 1)
        //if teacher's method is used
        // if (primeno(n, 2) == 1)
        printf("%d is a prime number\n", n);
    else
        printf("%d is nnot a prime number\n", n);
    return 0;
}