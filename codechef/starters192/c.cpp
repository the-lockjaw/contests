#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        vector<int> P_mod(n);
        vector<vector<int>> occ(3);
        P_mod[0] = A[0] % 3;
        occ[P_mod[0]].push_back(0);
        bool has_bad = (P_mod[0] == 0);
        for (int i = 1; i < n; i++)
        {
            P_mod[i] = (P_mod[i - 1] + A[i]) % 3;
            occ[P_mod[i]].push_back(i);
            if (P_mod[i] == 0)
            {
                has_bad = true;
            }
        }

        if (!has_bad)
        {
            cout << "Yes\n";
            continue;
        }

        int last_bad = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (P_mod[i] == 0)
            {
                last_bad = i;
                break;
            }
        }

        bool found = false;
        for (int k = last_bad + 1; k <= n; k++)
        {
            if (P_mod[k - 1] == 0)
            {
                continue;
            }
            int r = P_mod[k - 1];
            auto it = upper_bound(occ[r].begin(), occ[r].end(), k - 2);
            int count = it - occ[r].begin();
            if (count == 0)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}