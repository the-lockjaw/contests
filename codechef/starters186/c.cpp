#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> deficit(5, 0);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        deficit[5 - i - 1] = 10 - a;
        sum += a;
    }
    int gold = 0;
    sort(deficit.begin(), deficit.end());
    int required = 35 - sum;
    if (required > 0)
    {
        for (int i = 4; i >= 0; i--)
        {
            required -= deficit[i];
            gold += 100;
            if (required <= 0)
                break;
        }
    }
    cout << gold << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
