#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findCoins(vector<int> &numWays)
    {
        int N = numWays.size();
        vector<int> coins;
        vector<int> dp(N + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; i++)
            if (dp[i] < numWays[i - 1])
            {
                coins.push_back(i);
                for (int j = i; j <= N; j++)
                    dp[j] += dp[j - i];
            }

        for (int i = 1; i <= N; i++)
            if (dp[i] != numWays[i - 1])
                return {};

        return coins;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ans = sol.findCoins(v);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}