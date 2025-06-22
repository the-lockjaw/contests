#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> ans;
        vector<bool> taken(n + 1, false);
        if (m < n || m > ((n * (n + 1)) / 2))
        {
            cout << -1 << endl;
            continue;
        }
        long long more_needed = m - n;
        long long max_available = n;
        while (more_needed > 0)
        {
            if (more_needed < max_available)
            {
                ans.push_back(more_needed + 1);
                taken[more_needed + 1] = true;
                break;
            }
            more_needed -= max_available - 1;
            taken[max_available] = true;
            ans.push_back(max_available);
            max_available--;
        }
        for (long long i = 1; i <= n; i++)
            if (!taken[i])
                ans.push_back(i);

        cout << ans[0] << endl;
        for (long long i = 0; i < ans.size() - 1; i++)
            cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}