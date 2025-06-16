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
        int w, h, a, b, p, q, r, s;
        cin >> w >> h >> a >> b >> p >> q >> r >> s;
        int m = (r - p - a) > 0 ? r - p - a : r - p;
        int n = (s - q - b) > 0 ? s - q - b : s - q;
        if ((m && !(m % a)) || (n && !(n % b)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}