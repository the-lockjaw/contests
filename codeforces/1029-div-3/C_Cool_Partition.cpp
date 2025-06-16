#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    unordered_set<int> st,st2;
    int ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.find(v[i]) != st.end())
        {
            cout<<"not unique for first partition"<<endl;
            if (st2.find(v[i]) != st2.end())
            {
                cout<<"not unique for current partition"<<endl;
                ans++;
                st2.clear();
            }else{
                cout<<"unique for current partintion"<<endl;
                st2.insert(v[i]);
            }
        }
        else
        {
            cout<<"uniquw"<<endl;
            st.insert(v[i]);
            st2.insert(v[i]);
            ans = 1;
        }
        cout << "v[i] = " << v[i] << endl;
        cout << "Answer = " << ans << endl;
        cout<<endl;
    }
    cout << ans << endl;
    cout <<"-----------------"<< endl;
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