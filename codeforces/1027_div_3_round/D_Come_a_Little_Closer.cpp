#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    long long mnx = a[0].first, mxx = a[0].first;
    long long mny = a[0].second, mxy = a[0].second;

    for (int i = 0; i < n; i++)
    {
        mnx = min(mnx, a[i].first);
        mxx = max(mxx, a[i].first);
        mny = min(mny, a[i].second);
        mxy = max(mxy, a[i].second);
    }

    long long ans = (mxx - mnx + 1) * (mxy - mny + 1);

    for (int i = 0; i < n; i++)
    {
        vector<long long> x, y;
        set<pair<long long, long long>> used;

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                x.push_back(a[j].first);
                y.push_back(a[j].second);
                used.insert({a[j].first, a[j].second});
            }
        }

        long long lx = *min_element(x.begin(), x.end());
        long long rx = *max_element(x.begin(), x.end());
        long long ly = *min_element(y.begin(), y.end());
        long long ry = *max_element(y.begin(), y.end());

        // Try key positions that could minimize the area
        set<pair<long long, long long>> candidates;

        // Positions at existing coordinates (don't expand bounding box)
        set<long long> sx(x.begin(), x.end());
        set<long long> sy(y.begin(), y.end());

        for (auto px : sx)
        {
            for (auto py : sy)
            {
                candidates.insert({px, py});
            }
        }

        // Positions that could create linear arrangements
        for (auto px : sx)
        {
            candidates.insert({px, ly - 1});
            candidates.insert({px, ry + 1});
        }
        for (auto py : sy)
        {
            candidates.insert({lx - 1, py});
            candidates.insert({rx + 1, py});
        }

        for (auto [nx, ny] : candidates)
        {
            if (used.find({nx, ny}) == used.end())
            {
                long long l = min(lx, nx);
                long long r = max(rx, nx);
                long long d = min(ly, ny);
                long long u = max(ry, ny);

                ans = min(ans, (r - l + 1) * (u - d + 1));
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}