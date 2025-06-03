#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int q = 0;
    int med_index = (n+1)/2;
    int a0;
    cin >> a0;
    a0 = abs(a0);
    for (int i = 0; i < n - 1; ++i)
    {
        int a;
        cin >> a;
        if (abs(a) < a0)
        {
            q++;
        }
    }
    if (q == med_index)
    {
        if(n&1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    else if (q > med_index)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return;
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