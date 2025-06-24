#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(1);
        parent[1] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (parent[v] == -1)
                {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<long long> threat(n + 1);

        for (int i = 1; i <= n; i++)
        {
            long long max_threat = a[i];
            vector<int> path;
            int curr = i;

            while (curr != 0)
            {
                path.push_back(curr);
                long long sum = 0;
                for (int j = 0; j < path.size(); j++)
                {
                    if (j % 2 == 0)
                    {
                        sum += a[path[j]];
                    }
                    else
                    {
                        sum -= a[path[j]];
                    }
                }

                max_threat = max(max_threat, sum);

                curr = parent[curr];
            }

            threat[i] = max_threat;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << threat[i];
            if (i < n)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}