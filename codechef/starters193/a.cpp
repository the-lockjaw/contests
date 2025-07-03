#include <iostream>
using namespace std;

int countDivisors(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            count++;
    return count;
}

int countOddDivisors(int n)
{
    while (n % 2 == 0)
        n /= 2;
    return countDivisors(n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int oddDivisors = countOddDivisors(n);
        int totalDivisors = countDivisors(n);
        int evenDivisors = totalDivisors - oddDivisors;

        cout << oddDivisors << " " << evenDivisors << endl;
    }

    return 0;
}