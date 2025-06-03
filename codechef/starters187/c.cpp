#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (k < min(x, y))
    {
        cout << "Bob" << endl;
    }
    else
    {
        if (max(x, y) - k > k)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
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