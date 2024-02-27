#include <stdio.h>

void input(int *array, int n)
{
    for (int i=0;i<=n;i++){
        scanf("%d", &i);
    }
}
void output(int *array, int n)
{
    for (int i=0;i<=n;i++){
        printf("%d", i);
    }
}
int main()
{
    int size = 5;
    int a[size], b[size], c[size];
    printf("Input nos. ");
    input(a, size);
    printf("Input nos. ");
    input(b, size);
    // input(c, size);
    output(a, size);
    output(b, size);
    

}