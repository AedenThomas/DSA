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