#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    bool x = (((m - (n * b)) / (a - b)) >= 0) && (!((m - (n * b)) % (a - b)));
    bool y = ((((n * a) - m) / (a - b)) >= 0) && (!(((n * a) - m) % (a - b)));
    if(x&&y){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
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
