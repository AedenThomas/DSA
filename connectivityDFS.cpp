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
