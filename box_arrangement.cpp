#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &v, int n)
{
    sort(v.begin(), v.end());

    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            swap(v[i], v[i + 1]);
        }
        reverse(v.begin(), v.end());
    }
    else
    {
        int x = v[n - 1];
        v.pop_back();
        for (int i = 0; i < n - 2; i += 2)
        {
            swap(v[i], v[i + 1]);
        }
        reverse(v.begin(), v.end());
        v.push_back(v[n - 1]);
        swap(v[n - 2], v[n - 1]);
    }
}

int main()
{
    int n;
    cout << "enter the number of boxes" << endl;
    cin >> n;
    vector<int> v(n);

    cout << "enter the values in the boxes" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<char> vc(n - 1);
    cout << "enter the sign " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> vc[i];
    }

    solve(v, n);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        cout << v[i] << " " << vc[i] << "  ";
        i++;
        j++;
    }

    return 0;
}