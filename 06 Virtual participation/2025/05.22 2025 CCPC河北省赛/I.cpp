#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[500010];
int val[500010];
int ans[500010];
int dep[500010];
void dfs(int u,int fa)
{
    val[u]=g[u].size();
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        val[u]+=val[v];
    }
}
void dfs1(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        
        int vv=val[v];
        int uu=val[u]-vv;
        val[u]-=vv;
        val[v]+=uu;
        
        ans[v]=ans[u]+vv-uu;
        dfs1(v,u);

        val[v]=vv;
        val[u]=uu+vv;
        
    }
}
// 3  1  3*1
// 1  0  4*2
// 2  1  3*2
// 4  2  2*1
//前n时刻的扩散量
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
    int res=0;
    for(int i=1;i<=n;i++) res+=1ll*(n-dep[i])*g[i].size();
    ans[1]=res;
    
    dfs1(1,0);
    int mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,ans[i]);
    vector<int>a;
    
    for(int i=1;i<=n;i++) if(ans[i]==mx) a.push_back(i);
    cout<<a.size()<<"\n";

    for(auto i:a) cout<<i<<" ";
    cout<<"\n";
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