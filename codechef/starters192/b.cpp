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
        int min_seconds = INT_MAX;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        if (v[0])
            v[0]--;
        for (int i = 0; i < n; i++)
            min_seconds = min(min_seconds, max(v[i] + 1, i));

        cout << min_seconds << endl;
    }
    return 0;
}