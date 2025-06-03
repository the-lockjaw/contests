#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool one = false, two = false;
    bool ans = false;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        if (!(sum % 3))
        {
            ans = true;
        }
        else if (sum % 3 == 1)
        {
            if (one)
            {
                ans = true;
            }
            one = true;
        }
        else
        {
            if (two)
            {
                ans = true;
            }
            two = true;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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