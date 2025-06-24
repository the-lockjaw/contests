#include <iostream>
#include <vector>
#include <utility>
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
        vector<vector<int>> graph(n + 1);
        vector<int> deg(n + 1, 0);
        vector<pair<int, int>> edges;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++;
            deg[v]++;
            edges.push_back({u, v});
        }

        if (n == 2)
        {
            cout << "NO\n";
            continue;
        }

        int Y = -1;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] >= 2)
            {
                Y = i;
                break;
            }
        }

        if (Y == -1)
        {
            cout << "NO\n";
            continue;
        }

        int X = graph[Y][0];
        int W = graph[Y][1];

        vector<pair<int, int>> directed_edges;

        for (auto &e : edges)
        {
            int u = e.first, v = e.second;
            if ((u == X && v == Y) || (u == Y && v == X))
            {
                directed_edges.push_back({X, Y});
            }
            else if ((u == Y && v == W) || (u == W && v == Y))
            {
                directed_edges.push_back({Y, W});
            }
            else if (u == X || v == X)
            {
                if (u == X)
                {
                    directed_edges.push_back({X, v});
                }
                else
                {
                    directed_edges.push_back({X, u});
                }
            }
            else if (u == W || v == W)
            {
                if (u == W)
                {
                    directed_edges.push_back({v, W});
                }
                else
                {
                    directed_edges.push_back({u, W});
                }
            }
            else if (u == Y || v == Y)
            {
                if (u == Y)
                {
                    directed_edges.push_back({v, Y});
                }
                else
                {
                    directed_edges.push_back({u, Y});
                }
            }
            else
            {
                if (u < v)
                {
                    directed_edges.push_back({u, v});
                }
                else
                {
                    directed_edges.push_back({v, u});
                }
            }
        }

        cout << "YES\n";
        for (auto &e : directed_edges)
        {
            cout << e.first << " " << e.second << "\n";
        }
    }

    return 0;
}