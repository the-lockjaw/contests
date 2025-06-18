#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string l, r;
        cin >> l >> r;

        int n = l.length();
        int ans = 0;

        // The key insight: we want to minimize f(l,x) + f(x,r)
        // For each position i:
        // - If l[i] == r[i], then x[i] should equal l[i] = r[i] (contributes 2)
        // - If l[i] != r[i], then x[i] can be chosen optimally

        for (int i = 0; i < n; i++)
        {
            if (l[i] == r[i])
            {
                // x[i] must equal l[i] = r[i] to stay in range [l,r]
                ans += 2;
            }
            else
            {
                // l[i] != r[i], we have choices for x[i]
                // We can choose x[i] = l[i] (contributes 1 + 0)
                // We can choose x[i] = r[i] (contributes 0 + 1)
                // We can choose x[i] = something else if possible (contributes 0 + 0)

                // The question is: can we choose something else?
                // We need l[i] <= x[i] <= r[i]
                // If r[i] - l[i] >= 2, we can choose a digit between them
                // Otherwise, we're forced to choose either l[i] or r[i]

                if (r[i] - l[i] >= 2)
                {
                    ans += 0; // can choose a digit that matches neither
                }
                else
                {
                    ans += 1; // must choose either l[i] or r[i]
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}