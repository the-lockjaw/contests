#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int no_of_ones = count(s.begin(), s.end(), '1');

    if (no_of_ones == 0)
    {
        cout << "Alice\n";
        return;
    }

    if (no_of_ones <= k)
    {
        cout << "Alice\n";
        return;
    }

    if (k == 1)
    {
        cout << "Bob\n";
        return;
    }

    if (n >= k * 2)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}