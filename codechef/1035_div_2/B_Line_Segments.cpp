#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long dx = px - qx;
        long long dy = py - qy;
        long long sd = dx * dx + dy * dy;
        long long td = accumulate(v.begin(), v.end(), 0LL);
        long long max_a = *max_element(v.begin(), v.end());

        if (sd > td * td)
        {
            cout << "No" << endl;
        }
        else if (2 * max_a <= td)
        {
            cout << "Yes" << endl;
        }
        else
        {
            long long gap = 2 * max_a - td;
            if (sd >= gap * gap)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}