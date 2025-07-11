#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        vector<int> freq(n + 2, 0);
        for (int num : nums)
                freq[num]++;

        int mex = 0;
        while (freq[mex] > 0)
            mex++;
        int maxM = min(mex, n);

        vector<int> diff(n + 2, 0);
        for (int m = 0; m <= maxM; m++)
        {
            int left = freq[m], right = n - m;
            if (left <= right)
            {
                diff[left]++;
                if (right + 1 <= n)
                    diff[right + 1]--;
            }
        }

        vector<int> result(n + 1);
        int running = 0;
        for (int k = 0; k <= n; k++)
        {
            running += diff[k];
            result[k] = running;
        }

        for (int i = 0; i <= n; i++)
        {
            cout << result[i];
            if (i < n)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
