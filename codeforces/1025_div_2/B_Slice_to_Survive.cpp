#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 1;
    int rows, cols;
    // cout << "b * m = " << b * m << endl;
    // cout << "n * a = " << n * a << endl;
    // cout << "m * (n - b + 1) = " << m * (n - b + 1) << endl;
    // cout << "n * (m - a + 1) = " << n * (m - a + 1) << endl;
    if (b * m > n * a)
    {
        rows = n;
        cols = a;
    }
    else
    {
        rows = b;
        cols = m;
    }
    if (rows * cols > m * (n - b + 1))
    {
        cols = m;
        rows = n - b + 1;
    }
    if (rows * cols > n * (m - a + 1))
    {
        rows = n;
        cols = m - a + 1;
    }
    // cout<<"Rows = "<<rows<<endl;
    // cout<<"Cols = "<<cols<<endl;
    while (rows > 1)
    {
        rows = (rows + 1) / 2;
        ans++;
    }
    while (cols > 1)
    {
        cols = (cols + 1) / 2;
        ans++;
    }
    cout << ans << endl;
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