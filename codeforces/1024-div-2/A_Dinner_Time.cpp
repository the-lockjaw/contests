#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p)
    {
        cout << "YES" << endl;
    }
    else
    {
        if (((n / p) * q) == m)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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