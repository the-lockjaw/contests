#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
    // for (auto a : v)
    //     cout << a << " ";
    // cout << endl;
}

// z & ~y

vector<int> get_perm(int n, int x)
{
    vector<int> not_found;
    vector<int> ans(n, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << "x = " << x << endl;
        cout << "i = " << i << endl;
        int a = x & ~i;
        cout << "a = " << a << endl;
        // if (ans[a] == -1 && a < n)
        // {
        //     ans[a] = i;
        // }
        // else
        // {
        //     not_found.push_back(i);
        // }
        cout << endl;
    }
    cout << endl;
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    print_vector(get_perm(n, x));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
