#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n;
vector<int>g[100010];
int dep[100010];
void dfs(int u,int fa)
{
    dep[u]=1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        dep[u]=max(dep[v]+1,dep[u]);
    }
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(auto v:g[1]) ans+=dep[v];
    cout<<ans<<"\n";
}

int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}