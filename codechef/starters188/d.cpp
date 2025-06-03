#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long min_time = n;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            min_time = min(min_time, a[i] + n - i - 1);
        }

        cout << min_time << "\n";
    }

    return 0;
}