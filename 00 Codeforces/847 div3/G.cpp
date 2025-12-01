#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n,m;
    cin>>n>>m;
    int p,b;
    cin>>p>>b;
    vector<bool>p1(n),b1(n);
    for(int i=0;i<p;i++)
    {
        int x;
        cin>>x;
        p1[x]=1;
    }


    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        b1[x]=1;
    }

    vector<vector<int>>g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}