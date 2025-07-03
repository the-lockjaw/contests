#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ones = 0, twos = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
                ones++;
            else
                twos++;
        }
        if (ones & 1)
            cout << twos << "\n";
        else
            cout << min(ones / 2, twos) << "\n";
    }

    return 0;
}