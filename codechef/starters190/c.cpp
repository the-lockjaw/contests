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
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int parries = 0;
        int power_level = x;
        for (int i = 0; i < n; i++)
        {
            int allowed_parries = x - a[i];
            if (parries > allowed_parries)
            {
                power_level = power_level + (parries - allowed_parries);
                parries = allowed_parries;
            }
            if (power_level >= b[i])
            {
                parries++;
                power_level--;
            }
        }
        cout << parries << endl;
    }
    return 0;
}