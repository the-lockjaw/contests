#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
    {
        cin >> a;
    }
    vector<int> local_maximas;
    vector<int> local_minimas;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i - 1] < v[i] && v[i] > v[i + 1])
        {
            local_maximas.push_back(i);
        }
        if (v[i - 1] > v[i] && v[i] < v[i + 1])
        {
            local_minimas.push_back(i);
        }
    }
    int i = 0;
    int j = 0;
    long long ans = 0;
    while (i < local_maximas.size() && j < local_minimas.size())
    {
        while (local_maximas[i] > local_minimas[j])
        {
            j++;
        }
        ans += 1;
        if (i == local_maximas.size() - 1)
        {
            ans += n - 2 - local_minimas[j];
        }
        else
        {
            ans += local_maximas[i + 1] - local_minimas[j] - 1;
        }
        if (j == 0)
        {
            ans += local_maximas[i] - 1;
        }
        else
        {
            ans += local_maximas[i] - local_minimas[j-1] - 1;
        }

        i++;
        j++;
    }
    cout << ans << endl;
}