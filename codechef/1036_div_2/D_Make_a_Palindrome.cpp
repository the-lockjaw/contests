#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i])
            return false;
    return true;
}

bool custom_comp(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        if (is_palindrome(a) || k == 1)
        {
            cout << "YES\n";
            continue;
        }

        vector<pair<int, int>> vals;
        for (int i = 0; i < n; i++)
            vals.push_back({a[i], i});
        sort(vals.begin(), vals.end());

        int m = k - 1;
        vector<pair<int, int>> smallest(vals.begin(), vals.begin() + m);
        sort(smallest.begin(), smallest.end(), custom_comp);

        vector<int> seq;
        for (auto &p : smallest)
            seq.push_back(p.first);

        cout << (is_palindrome(seq) ? "YES\n" : "NO\n");
    }
}
