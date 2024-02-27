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









// Implement Brute Force String matching algorithm and find the time taken to find the pattern in the given string.
#include <iostream>

using namespace std;

void bruteForceStringMatching(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i < n - m + 1; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index: " << i << endl;
        }
    }
}

int main()
{
    string text = "AEDEN GEO THOMAS";
    string pattern = "GEO";

    clock_t start = clock();
    bruteForceStringMatching(text, pattern);
    clock_t end = clock();
    cout << fixed << "Time taken for brute force string matching is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}








// Sort a given set of elements using Quick sort and find the time taken to sort the elements.
#include <iostream>

using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); // index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout << fixed << "Time taken for quick sort is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}







// Sort a given set of elements using Merge sort and find the time taken to sort the elements.
#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout << fixed << "Time taken for merge sort is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}








#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void kruskals();
int c[10][10], n;

int main()
{
    int i, j;
    cout << "enter the no. of vertices:\t";
    cin >> n;
    cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    clock_t start = clock();
    kruskals();
    clock_t end = clock();
    cout << fixed << "Time taken for Kruskal's algorithm is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
}

void kruskals()
{
    int i, j, u, v, a, b, min;
    int ne = 0, mincost = 0;
    int parent[10];
    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }
    while (ne != n - 1)

    {
        min = 9999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        while (parent[u] != 0)
        {
            u = parent[u];
        }
        while (parent[v] != 0)
        {
            v = parent[v];
        }
        if (u != v)
        {

            parent[v] = u;
            ne = ne + 1;
            mincost = mincost + min;
        }
        c[a][b] = c[b][a] = 9999;
    }

    cout << "mincost=" << mincost << endl;
}









// Implement Prim's algorithm to compute minimum spanning tree of a given graph.

#include <iostream>

using namespace std;
int c[10][10], n;
void prims()
{
    int i, j, u, v, min;
    int ne = 0, mincost = 0;
    int elec[10];
    for (i = 1; i <= n; i++)
    {
        elec[i] = 0;
    }
    elec[1] = 1;
    while (ne != n - 1)
    {
        min = 9999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (elec[i] == 1)
                {
                    if (c[i][j] < min)
                    {
                        min = c[i][j];

                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (elec[v] != 1)
        {

            cout << u << "----->" << v << "=" << min << endl;
            elec[v] = 1;
            ne = ne + 1;
            mincost = mincost + min;
        }
        c[u][v] = c[v][u] = 9999;
    }

    cout << "Minimum cost of spanning tree is: " << mincost << endl;
}

int main()
{
    int i, j;
    cout << "enter the no. of vertices:\t";
    cin >> n;
    cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    clock_t start = clock();
    prims();
    clock_t end = clock();
    cout << fixed << "Time taken for Prim's algorithm is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
}











// Print all the nodes reachable from a given starting node in a digraph using BFS method and find the time taken to print all the nodes.

#include <iostream>

using namespace std;
int a[10][10], n;
void bfs(int);
int main()
{
    int i, j, src;
    cout << "enter the no. of vertices:\t";

    scanf("%d", &n);
    cout << "Enter the adjacency matrix:\n";

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "enter the source node:\t";
    cin >> src;

    clock_t start = clock();
    bfs(src);
    clock_t end = clock();
    cout << fixed << "Time taken for BFS is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
}

void bfs(int src)
{
    int q[10], f = 0, r = -1, vis[10], i, j;
    for (j = 1; j <= n; j++)
    {
        vis[j] = 0;
    }
    vis[src] = 1;
    r = r + 1;
    q[r] = src;
    while (f <= r)
    {
        i = q[f];
        f = f + 1;
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 && vis[j] != 1)
            {
                vis[j] = 1;
                r = r + 1;
                q[r] = j;
            }
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (vis[j] != 1)
        {
            cout << "node " << j << " is not reachable from " << src << endl;

        }
        else
        {
            cout << "node " << j << " is reachable from " << src << endl;
        }
    }
}














// Print all the nodes reachable from a given starting node in a digraph using BFS method and find the time taken to print all the nodes.
#include <iostream>

using namespace std;

int a[10][10], n, vis[10];
int dfs(int);
int main()
{
    int i, j, src, ans;

    for (j = 1; j <= n; j++)
    {
        vis[j] = 0;
    }
    cout << "enter the no. of nodes:\t";
    cin >> n;
    cout << "enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "enter the source node:\t";
    cin >> src;
    clock_t start = clock();
    ans = dfs(src);
    clock_t end = clock();
    
    if (ans == 1)
    {
        cout<<"Graph is connected"<<endl;

    }
    else
    {
        cout<<"Graph is not connected"<<endl;

    }
    cout << fixed << "Time taken for BFS is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    
}

int dfs(int src)
{
    int j;
    vis[src] = 1;
    for (j = 1; j <= n; j++)
    {
        if (a[src][j] == 1 && vis[j] != 1)
        {
            dfs(j);
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (vis[j] != 1)
        {
            return 0;
        }
    }
    return 1;
}














// Implement Horspool’s algorithm for String Matching.

#include <stdio.h>
#include <string.h>

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













// Sort a given set of elements using the Heap sort method and find the time taken to sort the elements.
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
    heapSort(arr, n);
    clock_t end = clock();
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout << fixed << "Time taken for heap sort is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}














// Implement All Pair Shortest paths problem using Floyd's algorithm and find the time taken to find the shortest paths.
#include <iostream>

using namespace std;
int a[10][10],n;
void floyds()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    cout<<"\nShortest paths are:\n";

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<" ";

        }
        cout<<endl;

    }
}

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    int i, j;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
    cout<<"Enter the cost matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }
    clock_t start = clock();
    floyds();
    clock_t end = clock();
    cout<<fixed<<"Time taken for Floyd's algorithm is: "<<(((double)end - (double)start) / (double)CLOCKS_PER_SEC)<<endl;

}














// Implement a solution for Knapsack problem using dynamic programming and find the time taken to find the optimal solution.

#include <iostream>

using namespace std;

void knapsack(int wt[], int val[], int n, int W)
{
    int i, j;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    cout << "The output is : ";
    // only if askes to print the items that are put in the knapsack
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nOptimal value is: " << K[n][W] << endl;
}

int main()
{
    int n, W;
    cout << "Enter the number of items:\n";
    cin >> n;
    cout << "Enter the weights of items:\n";
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the values of items:\n";
    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << "Enter the capacity of knapsack:\n";
    cin >> W;
    clock_t start = clock();
    knapsack(wt, val, n, W);
    clock_t end = clock();
    cout << fixed << "Time taken for Knapsack algorithm is: " << (((double)end - (double)start) / (double)CLOCKS_PER_SEC) << endl;
    return 0;
}
