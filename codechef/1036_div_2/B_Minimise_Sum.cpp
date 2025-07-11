#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> a(n), pm(n), ps(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        pm[0] = a[0];
        ps[0] = pm[0];

        for (int i = 1; i < n; i++)
        {
            pm[i] = min(pm[i - 1], a[i]);
            ps[i] = ps[i - 1] + pm[i];
        }

        long long ans = ps[n - 1];
        long long mini = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            long long prev_min = (i > 0) ? pm[i - 1] : mini;
            long long prev_sum = (i > 0) ? ps[i - 1] : 0LL;
            long long combined = a[i] + a[i + 1];
            long long take = min(prev_min, combined);
            ans = min(ans, prev_sum + take);
        }

        cout << ans << "\n";
    }

    return 0;
}