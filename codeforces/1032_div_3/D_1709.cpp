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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<int, int>> operations;
        vector<int> all_elements;
        for (int i = 0; i < n; i++)
        {
            all_elements.push_back(a[i]);
            all_elements.push_back(b[i]);
        }
        sort(all_elements.begin(), all_elements.end());

        set<int> should_be_in_a;
        for (int i = 0; i < n; i++)
        {
            should_be_in_a.insert(all_elements[i]);
        }
        for (int i = 0; i < n; i++)
        {
            bool a_correct = should_be_in_a.count(a[i]);
            bool b_correct = !should_be_in_a.count(b[i]);

            if (!a_correct && !b_correct)
            {
                swap(a[i], b[i]);
                operations.push_back({3, i + 1});
            }
        }

        for (int pass = 0; pass < n - 1; pass++)
        {
            for (int i = 0; i < n - 1 - pass; i++)
            {
                if (a[i] > a[i + 1])
                {
                    swap(a[i], a[i + 1]);
                    operations.push_back({1, i + 1});
                }
            }
        }

        for (int pass = 0; pass < n - 1; pass++)
        {
            for (int i = 0; i < n - 1 - pass; i++)
            {
                if (b[i] > b[i + 1])
                {
                    swap(b[i], b[i + 1]);
                    operations.push_back({2, i + 1});
                }
            }
        }

        cout << operations.size() << "\n";
        for (auto op : operations)
        {
            cout << op.first << " " << op.second << "\n";
        }
    }

    return 0;
}