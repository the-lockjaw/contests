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
        int zeros, ones, twos;
        cin >> zeros >> ones >> twos;
        if (zeros <= twos)
            cout << "Yes" << endl;
        else if ((zeros == twos + 1) && (!ones))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}