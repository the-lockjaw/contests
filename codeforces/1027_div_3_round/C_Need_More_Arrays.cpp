#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &a : nums)
    {
        cin >> a;
    }

    int arrays = 1;
    int last_kept = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > last_kept + 1)
        {
            // Start new array
            arrays++;
            last_kept = nums[i];
        }
    }

    cout << arrays << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}