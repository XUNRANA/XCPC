#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>u>>v;
    cout<<(n-1)*n-m<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}