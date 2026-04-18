#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int w,t,ed,m,u,ud;
    cin>>w>>t>>ed>>m>>u>>ud;
    if(m) cout<<"Repair\n";
    else if(t==w) cout<<"Run\n";
    else if(ed==ud) cout<<"Stop\n";
    else cout<<"Run\n";

    if((t+u>w)||m||(ed!=ud)) cout<<"No\n";
    else cout<<"Yes\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}