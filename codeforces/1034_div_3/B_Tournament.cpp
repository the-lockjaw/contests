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
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> v(n);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            maxi = max(v[i], maxi);
        }
        if (v[j - 1] == maxi)
        {
            cout << "YES\n";
            continue;
        }
        if (k == 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}