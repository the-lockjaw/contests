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
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        while (q--)
        {
            int index, value;
            cin >> index >> value;
            nums[index - 1] = value;
            int ans = 0;
            for (int i = 0; i < n - 1; i++)
                ans += min(nums[i], nums[i + 1]);
            cout << ans << endl;
        }
    }
    return 0;
}