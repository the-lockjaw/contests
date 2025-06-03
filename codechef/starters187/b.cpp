#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x = k / m;
    if (k % m)
        x++;
    int y = k / n;
    if (k % n)
        y++;
    int bob = min(n*y,m*x);
    cout<<(n*m)-bob<<endl;
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