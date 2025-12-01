#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<array<int,2>>g[200010];
map<int,int>cnt[200010];
map<pair<int,int>,int>gg;
int fa[200010];
int ans;
int a[200010];
void dfs(int u,int f)
{
    fa[u]=f;
    for(auto v:g[u])
    {
        if(v[0]==f) continue;
        if(a[v[0]]!=a[u]) ans+=v[1];
        cnt[u][a[v[0]]]+=v[1];
        dfs(v[0],u);
    }
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        cnt[i].clear();
        cin>>a[i];
    }
    gg.clear();
    
    for(int i=1;i<n;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
        gg[{u,v}]=c;
        gg[{v,u}]=c;
    }

    ans=0;
    dfs(1,0);
    while(q--)
    {
        int v,x;
        cin>>v>>x;
        if(a[v]==x)
        {
            cout<<ans<<"\n";
            continue;
        }

        int w=gg[{v,fa[v]}];

        if(fa[v]&&a[fa[v]]==x)
        {
            ans-=w;
        }
        else if(fa[v]&&a[fa[v]]==a[v])
        {
            ans+=w;
        }

        cnt[fa[v]][x]+=w;
        cnt[fa[v]][a[v]]-=w;
        
        ans+=cnt[v][a[v]];
        ans-=cnt[v][x];
        a[v]=x;
        cout<<ans<<"\n";
    }
    

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
