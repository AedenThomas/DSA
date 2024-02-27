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
