#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1000010];
int v[1000010];
int f[1000010];
int p[1000010];
int sz[1000010];
int mi[1000010];
void dfs(int u,int fa)
{
    f[u]=fa;
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        mi[u]=min(mi[u],mi[v]);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>v[i];
        mi[i]=v[i];
        p[v[i]]=i;
    }
    for(int i=2;i<=n;i++) 
    {
        int f;
        cin>>f;
        g[f].push_back(i);
        g[i].push_back(f);
    }

    dfs(p[0],0);

    int mx=0;
    for(auto i:g[p[0]])
    {
        mx=max(mx,sz[i]);
    }
    cout<<mx<<" ";
    
    for(int i=1;i<n;i++)
    {
        if(mi[p[i]]<i) cout<<"0 ";
        else cout<<n-sz[p[i]]<<" ";
    }
    cout<<n<<"\n";
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
