#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int mx[200010][2];
int a[200010];
void dfs(int u,int fa)
{
    mx[u][0]=max(a[u],a[u]+mx[fa][1]);
    mx[u][1]=max(-a[u],-a[u]+mx[fa][0]);
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void solve () 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<mx[i][0]<<" ";
    cout<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}