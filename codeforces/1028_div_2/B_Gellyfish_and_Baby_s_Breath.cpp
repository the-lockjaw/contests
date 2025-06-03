#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long power(long long base, long long exp)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);

    for (int &a : p)
    {
        cin >> a;
    }
    for (int &a : q)
    {
        cin >> a;
    }

    int maxPPos = 0;
    int maxQPos = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i] > p[maxPPos])
        {
            maxPPos = i;
        }
        if (q[i] > q[maxQPos])
        {
            maxQPos = i;
        }

        long long val1 = power(2, p[maxPPos]) + power(2, q[i - maxPPos]);
        long long val2 = power(2, p[i - maxQPos]) + power(2, q[maxQPos]);
        long long ans = max(val1, val2)%mod;

        cout << ans;
        if (i < n - 1)
            cout << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}