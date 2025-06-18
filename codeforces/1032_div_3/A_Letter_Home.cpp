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
        int n, s;
        cin >> n >> s;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            maxi = max(maxi, a);
            mini = min(mini, a);
        }
        if (s >= maxi)
        {
            cout << s - mini << endl;
        }
        else if (s <= mini)
        {
            cout << maxi - s << endl;
        }
        else
        {
            cout << 2 * min(abs(maxi - s), abs(mini - s)) + max(abs(maxi - s), abs(mini - s)) << endl;
        }
    }
    return 0;
}