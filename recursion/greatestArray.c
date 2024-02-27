// Design a recursive C routine to find the maximum value in a given integer array.
#include<stdio.h>
int max(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    else
        return (max(arr, n - 1) > arr[n - 1]) ? max(arr, n - 1) : arr[n - 1];
}
int main()
{
    int arr[] = {1, 2, 3, 15, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum element in the array is %d", max(arr, n));
    return 0;
}