#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * max(0LL, (long long)v[i] - i)) % M;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
