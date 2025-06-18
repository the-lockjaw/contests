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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
                maxi = max(maxi, matrix[i][j]);
            }
        }

        vector<int> row_count(n, 0), col_count(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == maxi)
                {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        int best_row = max_element(row_count.begin(), row_count.end()) - row_count.begin();
        int best_col = max_element(col_count.begin(), col_count.end()) - col_count.begin();

        bool use_row = row_count[best_row] >= col_count[best_col];
        bool possible = true;
        int fixed_idx = -1;

        if (use_row)
        {
            for (int i = 0; i < n && possible; i++)
            {
                if (i == best_row)
                    continue;
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == maxi)
                    {
                        if (fixed_idx == -1)
                            fixed_idx = j;
                        else if (fixed_idx != j)
                        {
                            possible = false;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < m && possible; j++)
            {
                if (j == best_col)
                    continue;
                for (int i = 0; i < n; i++)
                {
                    if (matrix[i][j] == maxi)
                    {
                        if (fixed_idx == -1)
                            fixed_idx = i;
                        else if (fixed_idx != i)
                        {
                            possible = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << (possible ? maxi - 1 : maxi) << endl;
    }
    return 0;
}