#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a == b)
            cout << 0;
        else if (a > b)
            if ((a & 1) == 1 && b == a - 1)
                cout << y;
            else
                cout << -1;
        else
        {
            long long r = 0;
            for (long long i = a; i < b; ++i)
            {
                r += (i & 1) ? x : min(x, y);
            }
            cout << r;
        }

        if (t)
            cout << '\n';
    }
    return 0;
}