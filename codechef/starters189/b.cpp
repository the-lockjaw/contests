#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    unordered_map<int, int> mp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (mp.find(a[i]) != mp.end())
        {
            mp[a[i]] = min(mp[a[i]], b);
        }
        else
        {
            mp[a[i]] = b;
        }
    }
    long long ans = 0;
    for (auto a : mp)
    {
        if (a.second < c)
            ans += (c - a.second);
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