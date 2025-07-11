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
        long long n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n & 1)
            cout << l << "\n";
        else
        {
            if (n == 2)
                cout << "-1\n";
            else
            {
                long long ans = l;
                while (true)
                {
                    bool valid = true;
                    for (int pos = 0; pos < 64; pos++)
                    {
                        long long mask = 1LL << pos;
                        if ((l & mask) != 0 && (ans & mask) != 0)
                        {
                            ans += mask;
                            ans &= ~(mask - 1);
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                        break;
                }
                if (ans > r)
                    cout << "-1\n";
                else if (k <= n - 2)
                    cout << l << "\n";
                else
                    cout << ans << "\n";
            }
        }
    }

    return 0;
}