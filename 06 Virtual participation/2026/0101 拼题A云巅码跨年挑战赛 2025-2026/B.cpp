#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<d<<"\n";
    if(d>=a) cout<<"yi deng jiang";
    else if(d>=b) cout<<"er deng jiang";
    else if(d>=c) cout<<"san deng jiang";
    else cout<<"mei jiang T_T";
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}