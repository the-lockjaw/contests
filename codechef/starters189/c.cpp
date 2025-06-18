#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int p = 0, ans = 0, z = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        if (max(a + p + o * c, a + p + o * d) > max(b + p + z * d, b + p + z * c)){
            z++;
            ans = max(a + p + o * c, a + p + o * d);
        }else{
            o++;
            ans = max(b + p + z * d, b + p + z * c);
        }
        p = ans;
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