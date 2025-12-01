#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[1000010];
int sz[1000010];
int dp[1000010];
void dfs(int u,int fa)
{
    sz[u]=1;
    int mx=0;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        mx=max(mx,dp[v]);
    }
    dp[u]=mx+sz[u];
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<dp[1]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}