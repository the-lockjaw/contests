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
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        if (x > y)
        {
            int type_2_portions = k >= b ? ((k - b) / y + 1) : 0;
            k -= type_2_portions * y;
            int type_1_portions = k >= a ? ((k - a) / x + 1) : 0;
            cout << type_1_portions + type_2_portions << endl;
        }
        else
        {
            int type_1_portions = k >= a ? ((k - a) / x + 1) : 0;
            k -= type_1_portions * x;
            int type_2_portions = k >= b ? ((k - b) / y + 1) : 0;
            cout << type_1_portions + type_2_portions << endl;
        }
    }
    return 0;
}