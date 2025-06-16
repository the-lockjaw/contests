#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefix;
int n, m;

int getSum(int r1, int c1, int r2, int c2)
{
    if (r1 > r2 || c1 > c2 || r1 > n || c1 > m || r2 < 1 || c2 < 1)
    {
        return 0;
    }
    r1 = max(1, r1);
    c1 = max(1, c1);
    r2 = min(n, r2);
    c2 = min(m, c2);
    return prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> n >> m >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        int total_gold = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 'g')
                {
                    prefix[i][j]++;
                    total_gold++;
                }
            }
        }

        int min_gold_lost = total_gold;

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (grid[x][y] != '.')
                    continue;

                int r1 = x - k + 2;
                int c1 = y - k + 2;
                int r2 = x + k;
                int c2 = y + k;

                int gold_lost = getSum(r1, c1, r2, c2);
                min_gold_lost = min(min_gold_lost, gold_lost);
            }
        }

        cout << total_gold - min_gold_lost << "\n";
    }

    return 0;
}