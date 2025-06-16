#include <bits/stdc++.h>
using namespace std;

int fibo[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string ans = "";
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            int mini = min(a, min(b, c));
            int maxi = max(a, max(b, c));
            (mini >= fibo[n - 1] && maxi >= fibo[n - 1] + fibo[n - 2]) ? ans += "1" : ans += "0";
        }
        cout << ans << endl;
    }
}