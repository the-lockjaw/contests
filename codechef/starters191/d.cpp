#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> &a, vector<ll> &b, ll total, ll mid)
{
    int n = a.size();
    ll sum_x = 0;
    vector<ll> x(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
            return false;
        x[i] = min(b[i], mid - a[i]);
        sum_x += x[i];
    }
    ll S = total - sum_x;
    if (S < 0)
    {
        return false;
    }
    ll sum_cap = 0;
    for (int i = 0; i < n; i++)
    {
        ll remaining = mid - a[i] - x[i];
        ll option1 = remaining / 2;
        ll tokens_from_others = S - (b[i] - x[i]);
        if (tokens_from_others < 0)
        {
            continue;
        }
        sum_cap += min(option1, tokens_from_others);
    }
    return sum_cap >= S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll total = 0;
        for (ll x : b)
        {
            total += x;
        }
        ll low = 0;
        for (ll x : a)
        {
            if (x > low)
                low = x;
        }
        ll high = 0;
        for (int i = 0; i < n; i++)
        {
            high = max(high, a[i] + 2 * total - b[i]);
        }
        while (low < high)
        {
            ll mid = (low + high) / 2;
            if (check(a, b, total, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << low << '\n';
    }
    return 0;
}