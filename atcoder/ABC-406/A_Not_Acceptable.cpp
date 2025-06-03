#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c)
    {
        cout << "Yes" << endl;
    }
    else if (a == c && b >= d)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}