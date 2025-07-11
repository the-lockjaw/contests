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
        int n;
        cin >> n;
        vector<int> v(n), mini(n), maxi(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        mini[0] = v[0];
        maxi[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++)
            mini[i] = min(v[i], mini[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            maxi[i] = max(maxi[i + 1], v[i]);

        string ans = "";
        for (int i = 0; i < n; i++)
            if (v[i] == mini[i] || v[i] == maxi[i])
                ans += "1";
            else
                ans += "0";

        cout << ans << endl;
    }
    return 0;
}