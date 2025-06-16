#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v)
{
    for (auto a : v)
        cout << a << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    int odd_count = (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        if (i < odd_count)
        {
            v[i] = 2 * i + 1;
        }
        else
        {
            int max_even = (n % 2 == 0) ? n : n - 1;
            v[i] = max_even - 2 * (i - odd_count); // Even numbers in descending order
        }
    }

    print_vec(v);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}