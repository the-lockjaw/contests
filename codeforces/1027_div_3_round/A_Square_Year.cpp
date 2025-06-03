#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int x = stoi(s);
    int b = sqrt(x), a = 0;
    if ((a + b) * (a + b) == x)
        cout << a << " " << b << endl;
    else
        cout << "-1" << endl;
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