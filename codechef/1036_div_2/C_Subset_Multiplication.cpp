#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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

        vector<long long> a(n);
        cin >> a[0];

        long long lcm = 1;

        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % a[i - 1] == 0)
                continue;

            long long g = gcd(a[i - 1], a[i]);
            long long rem = a[i - 1] / g;
            lcm = lcm * rem / gcd(lcm, rem);
            a[i] *= lcm;
        }

        cout << lcm << "\n";
    }

    return 0;
}