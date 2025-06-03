#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
    {
        cin >> a;
    }
    sort(v.begin(), v.end());
    if (!((v[0] + v[n - 1]) & 1))
    {
        cout << "0" << endl;
        return;
    }
    int largest_odd = -1, largest_even = -1, smallest_odd = -1, smallest_even = -1;
    for (int i = 0; i < n; i++)
    {
        if (smallest_even == -1 && !(v[i] & 1))
            smallest_even = i;
        if (smallest_odd == -1 && (v[i] & 1))
            smallest_odd = i;
        if (!(v[i] & 1))
            largest_even = i;
        if ((v[i] & 1))
            largest_odd = i;
    }
    if (v[0] & 1)
    {
        cout << min(smallest_even, n - largest_odd - 1) << endl;
    }
    else
    {
        cout << min(smallest_odd, n - largest_even - 1) << endl;
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