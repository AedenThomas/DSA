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