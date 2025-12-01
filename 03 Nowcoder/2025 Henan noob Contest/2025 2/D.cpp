#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
vector<int>g[100010];
int a[100010];
int r[100010];
int ans[33];
void dfs(int u,int fa)
{
    r[u]=a[u];
    if(fa) r[u]&=r[fa];
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) 
    {
        int c=0;
        for(int j=0;j<32;j++) if(r[i]>>j&1) c++;
        ans[c]++;
    }
    
    while(m--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

