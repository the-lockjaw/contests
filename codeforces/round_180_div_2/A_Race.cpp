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
        int a, x, y;
        cin >> a >> x >> y;
        int maxi = max(x, y);
        int mini = min(x, y);
        if (a < mini || a > maxi)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}