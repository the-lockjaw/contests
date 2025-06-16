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
        int n, k;
        cin >> n >> k;
        string s = "1";
        for (int i = 0; i < n - k - 1; i++)
        {
            s += "0";
        }
        for (int i = 0; i < k - 1; i++)
        {
            s += "1";
        }
        if(n!=k){
            s += "0";
        }
        cout << s << endl;
    }
    return 0;
}