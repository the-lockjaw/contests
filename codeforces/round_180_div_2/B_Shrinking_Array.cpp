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
        int n;
        cin >> n;
        int ans = -1;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 1; i < n - 1; i++)
        {

            if (abs(v[i] - v[i - 1]) <= 1 || abs(v[i] - v[i + 1]) <= 1)
            {
                ans = 0;
                break;
            }
            bool strictly_increasing = v[i] > v[i - 1] && v[i + 1] > v[i];
            bool strictly_decreasing = v[i] < v[i - 1] && v[i + 1] < v[i];
            if (!(strictly_decreasing || strictly_increasing))
            {
                ans = 1;
                break;
            }
        }

        if (v.size() == 2 && abs(v[0] - v[1]) <= 1)
            ans = 0;

        cout << ans << endl;
    }
    return 0;
}