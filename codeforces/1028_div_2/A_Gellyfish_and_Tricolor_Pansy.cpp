#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mini = min(a, min(b, min(c, d)));
    if (mini == b || mini == d)
    {
        cout << "Gellyfish" << endl;
    }
    else
    {
        cout << "Flower" << endl;
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