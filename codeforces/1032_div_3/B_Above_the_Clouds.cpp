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
        string s;
        cin >> n >> s;
        vector<int> mp(26, 0);
        mp[s[0] - 'a']++;
        mp[s[n - 1] - 'a']++;
        bool ans = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (mp[s[i] - 'a'])
            {
                ans = true;
                break;
            }
            mp[s[i] - 'a']++;
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}