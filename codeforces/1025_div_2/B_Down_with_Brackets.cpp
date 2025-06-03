#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s == "")
    {
        cout << "NO" << endl;
        return;
    }
    int balance = 0;
    int count = 0;
    for (auto a : s)
    {
        a == '(' ? ++balance : --balance;
        if (!balance)
            ++count;
    }
    if (count == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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