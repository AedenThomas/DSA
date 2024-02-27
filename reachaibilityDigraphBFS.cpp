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
