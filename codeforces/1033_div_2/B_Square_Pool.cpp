#include <bits/stdc++.h>
using namespace std;

bool isPotted(long long x, long long y, long long s)
{
    return (x == 0 || x == s) && (y == 0 || y == s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;

        int potted = 0;

        for (int i = 0; i < n; i++)
        {
            int dx, dy;
            long long x, y;
            cin >> dx >> dy >> x >> y;

            set<tuple<long long, long long, int, int>> visited;

            while (true)
            {
                if (isPotted(x, y, s))
                {
                    potted++;
                    break;
                }

                auto state = make_tuple(x, y, dx, dy);
                if (visited.count(state))
                    break;
                visited.insert(state);

                long long steps_x, steps_y;

                if (dx == 1)
                    steps_x = s - x;
                else
                    steps_x = x;

                if (dy == 1)
                    steps_y = s - y;
                else
                    steps_y = y;

                long long steps = min(steps_x, steps_y);

                x += dx * steps;
                y += dy * steps;

                if (steps == steps_x)
                    dx = -dx;
                if (steps == steps_y)
                    dy = -dy;
            }
        }

        cout << potted << "\n";
    }

    return 0;
}