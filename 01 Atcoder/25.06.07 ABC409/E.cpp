#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int a[N];
int dp[N];
int ans;
vector<pair<int,int>>g[N];
void dfs(int u,int fa)
{
    dp[u]=a[u];
    for(auto v1:g[u])
    {
        int v=v1.first;
        int w=v1.second;
        if(v==fa) continue;
        dfs(v,u);
        dp[u]+=dp[v];
        ans+=w*abs(dp[v]);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}