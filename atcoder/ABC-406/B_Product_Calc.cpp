#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long ans = 1;
    long long limit = 1;
    for (int j = 0; j < k; j++)
        limit *= 10;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        // Check if a is too large directly
        if (a >= limit)
        {
            ans = 1;
        }
        // Check for potential overflow without using floating point
        else if (ans > limit / a)
        {
            ans = 1;
        }
        else
        {
            ans *= a;
        }
    }

    cout << ans << endl;
    return 0;
}