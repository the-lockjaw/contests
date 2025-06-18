#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    n--;
    int ans = -1;
    while (n--)
    {
        int a;
        cin >> a;
        if (a != prev)
            ans = 2;
        prev = a;
    }
    cout<<ans<<endl;
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