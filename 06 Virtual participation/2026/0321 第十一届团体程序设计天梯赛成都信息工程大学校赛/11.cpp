#include <bits/stdc++.h>
using namespace std;

int n,u,v;
int ans[20010];
vector<int>g[20010];
int sz[20010];
void dfs(int u,int f,int s)
{
    ans[1]+=s;
    sz[u]=1;
    // cout<<u<<" "<<s<<"??\n";
    for(auto v:g[u])
    {
        if(v==f) continue;
        dfs(v,u,s+1);
        sz[u]+=sz[v];
    }
}
void dfs1(int u,int f)
{
    for(auto v:g[u])
    {
        if(v==f) continue;
        ans[v]=ans[u]-sz[v]+(n-sz[v]);
        
        int szv=sz[v];
        int szu=sz[u];

        sz[v]=n;
        sz[u]++;

        dfs1(v,u);

        sz[v]=szv;
        sz[u]=szu;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++) 
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    dfs1(1,0);
    int mx=ans[1];
    for(int i=1;i<=n;i++) mx=min(mx,ans[i]);
    for(int i=1;i<=n;i++) 
    {
        if(mx==ans[i])
        {
            cout<<i<<" "<<ans[i]<<"\n";
            return ;
        }
    }
     // for(int i=1;i<=n;i++) cout<<i<<" "<<sz[i]<<" "<<ans[i]<<"\n";
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}