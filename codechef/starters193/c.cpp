#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[i] = i + 1;

        int left = k - 1;
        int right = n - 1;
        while (left < right)
        {
            swap(p[left], p[right]);
            left++;
            right--;
        }

        for (auto a : p)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}