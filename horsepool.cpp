#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500
int t[MAX];

void shifttable(char p[])
{
    int i, j, m;
    m = strlen(p);
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[p[j]] = m - 1 - j;
}
int horspool(char src[], char p[])
{
    int i, j, k, m, n;
    n = strlen(src);
    m = strlen(p);
    printf("\nLength of text=%d", n);
    printf("\n Length of pattern=%d", m);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == src[i - k])) //p[m-1-k] is the last element of pattern and src[i-k] is the last element of text and k is the index of pattern
            k++;
        if (k == m)
            return (i - m + 1);
        else
            i += t[src[i]];
    }
    return -1;
}
int main()
{
    char src[100], p[100];
    int pos;
    printf("Enter the text in which pattern is to be searched:\n");
    gets(src);
    printf("Enter the pattern to be searched:\n");
    gets(p);
    clock_t start = clock();
    shifttable(p);
    pos = horspool(src, p);
    clock_t end = clock();
    if (pos >= 0)
        printf("\n The desired pattern was found starting from position %d", pos + 1);
    else
        printf("\n The pattern was not found in the given text\n");
    printf("\nTime taken for Horspool's algorithm is: %f", (((double)end - (double)start) / (double)CLOCKS_PER_SEC));
}