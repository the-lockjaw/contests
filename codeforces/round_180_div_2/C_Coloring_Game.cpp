#include <iostream>
#include <vector>
#include <algorithm>
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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long ans = 0;
        long long maxi = a[n - 1];

        for (int k = 2; k < n; k++)
        {
            long long x;
            if (k < n - 1)
                x = max(a[k], maxi - a[k]);
            else
                x = a[k];

            int left = 0;
            int right = k - 1;
            long long count = 0;
            while (left < right)
                if (a[left] + a[right] > x)
                {
                    count += (right - left);
                    right--;
                }
                else
                    left++;
            ans += count;
        }
        cout << ans << '\n';
    }
    return 0;
}