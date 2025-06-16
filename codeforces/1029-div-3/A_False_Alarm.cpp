#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    int first_one = -1;
    int last_one = -1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a)
        {
            if (first_one == -1)
            first_one = i;
            last_one = i;
        }
    }
    if (x >= n)
    {
        cout << "YES" << endl;
        return;
    }
    if (first_one == -1)
    {
        cout << "YES" << endl;
        return;
    }
    if (last_one - first_one + 1 <= x)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}