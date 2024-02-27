// Sort a given set of elements using Selection sort and find the time taken to sort the elements.
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n";
    printArray(arr, n);
    // Find the time taken to sort the elements
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout << fixed << "Time taken for selection sort is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}