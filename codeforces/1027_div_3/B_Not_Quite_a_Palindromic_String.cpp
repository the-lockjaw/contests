#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int zeros = 0, ones = 0;
    for (char c : s)
    {
        if (c == '0')
            zeros++;
        else
            ones++;
    }
    int pairs = n / 2;
    int min_k = max(pairs - zeros, pairs - ones);

    int max_k = pairs;

    if (k < min_k || k > max_k)
    {
        cout << "NO\n";
        return;
    }
    if ((zeros - pairs + k) % 2 != 0 || (ones - pairs + k) % 2 != 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}