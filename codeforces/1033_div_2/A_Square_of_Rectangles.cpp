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
        int l1, l2, l3, b1, b2, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        int x = -1;
        bool l_ok = false, b_ok = false;

        if ((l1 == l2 && l2 == l3) && b1 + b2 + b3 == l1)
        {
            cout << "YES" << endl;
            continue;
        }
        if ((b1 == b2 && b2 == b3) && l1 + l2 + l3 == b1)
        {
            cout << "YES" << endl;
            continue;
        }
        if ((l1 == l2 + l3) && b2 == b3 && b1 + b2 == l1)
        {
            cout << "YES" << endl;
            continue;
        }
        if ((b1 == b2 + b3) && l2 == l3 && l1 + l2 == b1)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}