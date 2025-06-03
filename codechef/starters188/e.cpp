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
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<tuple<int, int, int>> thieves;
        for (int i = 0; i < n; i++)
        {
            thieves.push_back({a[i], i, b[i]});
        }

        sort(thieves.begin(), thieves.end());

        vector<long long> result(n, 0);

        multiset<int> top_k_gold;
        long long current_sum = 0;

        for (int i = 0; i < n; i++)
        {
            int level = get<0>(thieves[i]);
            int orig_idx = get<1>(thieves[i]);
            int gold = get<2>(thieves[i]);

            result[orig_idx] = current_sum;

            if (top_k_gold.size() < k)
            {
                top_k_gold.insert(gold);
                current_sum += gold;
            }
            else
            {
                if (gold > *top_k_gold.begin())
                {
                    current_sum -= *top_k_gold.begin();
                    top_k_gold.erase(top_k_gold.begin());
                    top_k_gold.insert(gold);
                    current_sum += gold;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << result[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}