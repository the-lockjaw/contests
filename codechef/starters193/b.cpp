#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if (a == 0 && b == 0)
            cout << "No" << endl;
        else if (a > 0 && b == 0)
            cout << "Yes" << endl;
        else if (a == 0 && b > 0)
            cout << "No" << endl;
        else
        {
            if (b % a == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}