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
