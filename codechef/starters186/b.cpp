#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = -1;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            if (a >= 7)
            {
                if (ans == -1)
                    ans = b;
                else
                    ans = min(ans, b);
            }
        }
        cout << ans << endl;
    }
}
