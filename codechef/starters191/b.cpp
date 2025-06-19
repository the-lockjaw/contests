#include <bits/stdc++.h>
using namespace std;

bool is_valid(int a, int b)
{
    int g = gcd(a, b);
    return g > 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        if (is_valid(x, y))
            cout << 0 << '\n';
        else if (is_valid(x + 1, y) || is_valid(x, y + 1))
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}
