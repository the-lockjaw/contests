#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << (a[0] == 0 ? "YES" : "NO") << endl;
            continue;
        }

        long long numerator = 2LL * a[0] - a[1];
        long long denominator = n + 1;

        if (numerator % denominator != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        long long y = numerator / denominator;
        if (y < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        long long x = a[0] - n * y;
        if (x < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        bool valid = true;
        for (int i = 2; i < n; ++i)
        {
            long long expected = x * (i + 1) + y * (n - i);
            if (a[i] != expected)
            {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}