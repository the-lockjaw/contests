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
        vector<int> v(n);
        int maxi = INT_MIN;
        int mini = -1;
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 0; i < n; i++)
        {
            if (v[i] >= maxi)
                maxi = v[i];
            else
            {
                mini = v[i];
                break;
            }
        }
        if (mini == -1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << maxi << " " << mini << "\n";
        }
    }
    return 0;
}