#include <bits/stdc++.h>
using namespace std;

long long minSwapsToArrange(const vector<int> &arr, const vector<int> &positions)
{
    vector<int> onesPositions;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            onesPositions.push_back(i);
        }
    }

    vector<int> targetPositions = positions;
    sort(targetPositions.begin(), targetPositions.end());

    if (onesPositions.size() < targetPositions.size())
    {
        return LLONG_MAX;
    }

    int m = targetPositions.size();
    int n = onesPositions.size();

    // dp[i][j] = min cost to assign first i targets using first j ones
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));

    // Base case: 0 targets can be assigned with 0 cost
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // Fill DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (j > i)
            {
                dp[i][j] = dp[i][j - 1];
            }

            long long cost = abs(onesPositions[j - 1] - targetPositions[i - 1]);
            if (dp[i - 1][j - 1] != LLONG_MAX)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
            }
        }
    }

    return dp[m][n];
}

long long solveCase()
{
    int n, q;
    cin >> n >> q;

    string row1, row2;
    cin >> row1 >> row2;

    vector<int> r1(n), r2(n);
    for (int i = 0; i < n; i++)
    {
        r1[i] = row1[i] - '0';
        r2[i] = row2[i] - '0';
    }

    int totalOnes = 0;
    for (int i = 0; i < n; i++)
    {
        totalOnes += r1[i] + r2[i];
    }

    if (totalOnes < n + 1)
    {
        return -1;
    }

    long long minCost = LLONG_MAX;

    for (int k = 0; k < n; k++)
    {
        vector<int> row1Positions, row2Positions;

        for (int i = 0; i <= k; i++)
        {
            row1Positions.push_back(i);
        }

        for (int i = k; i < n; i++)
        {
            row2Positions.push_back(i);
        }

        long long cost1 = minSwapsToArrange(r1, row1Positions);
        long long cost2 = minSwapsToArrange(r2, row2Positions);

        if (cost1 != LLONG_MAX && cost2 != LLONG_MAX)
        {
            minCost = min(minCost, cost1 + cost2);
        }
    }

    return minCost == LLONG_MAX ? -1 : minCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cout << solveCase() << "\n";
    }

    return 0;
}