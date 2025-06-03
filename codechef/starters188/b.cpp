#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int even_sum = 0,odd_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(i&1)even_sum+=a;
        else odd_sum+=a;
    }
    cout<<max(odd_sum,even_sum)<<endl;
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