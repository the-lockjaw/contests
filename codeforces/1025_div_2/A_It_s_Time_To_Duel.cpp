#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    bool no_zeroes = true && v[0] && v[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        no_zeroes = no_zeroes && v[i];
        if (v[i] == 0 && v[i + 1] == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (no_zeroes)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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