#include <bits/stdc++.h>
using namespace std;

bool canLightAllCells(int n, const string &lights)
{
    vector<bool> lit(n, false);
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++)
    {
        if (lit[i])
        {
            continue;
        }

        bool found = false;
        if (i > 0 && lights[i - 1] == '1' && !used[i - 1])
        {
            used[i - 1] = true;
            lit[i - 1] = true;
            lit[i] = true;
            found = true;
        }
        else if (lights[i] == '1' && !used[i])
        {
            used[i] = true;
            lit[i] = true;
            if (i < n - 1)
            {
                lit[i + 1] = true;
            }
            found = true;
        }
        else if (i < n - 1 && lights[i + 1] == '1' && !used[i + 1])
        {
            used[i + 1] = true;
            lit[i] = true;
            lit[i + 1] = true;
            found = true;
        }

        if (!found)
        {
            return false;
        }
    }

    return true;
}

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
        string lights;
        cin >> n >> lights;

        if (canLightAllCells(n, lights))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}