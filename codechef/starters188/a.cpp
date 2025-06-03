#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r,b,p,q;
    cin>>r>>b>>p>>q;
    cout<<max(r*p,b*q)<<endl;
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