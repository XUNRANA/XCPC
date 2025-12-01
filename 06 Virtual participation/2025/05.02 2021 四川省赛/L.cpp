#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<int>g[100010];
int n,m,q;
int ans[500010];
vector<pair<int,int>>qu[110];
int d[100010];
int vt[100010];
int is[100010];
int w[100010];
void dij(int x)
{
    for(int i=1;i<=n;i++) d[i]=1e9,vt[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=n;i++) 
    if(w[i]<=x) 
    {
        d[i]=0;
        q.push({0,i});
    }
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v:g[u])
        {
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                q.push({d[v],v});
            }
        }
    }
}
void solve () 
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=q;i++)
    {
        int p,a;
        cin>>p>>a;
        qu[a].push_back({p,i});
    }
    for(int i=1;i<=100;i++)
    if(qu[i].size())
    {
        dij(i);
        // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
        // cout<<"\n";
        for(auto k:qu[i])
        {
            int u=k.first;
            int idx=k.second;
            if(d[u]==1e9) ans[idx]=-1;
            else ans[idx]=d[u];
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}


int32_t main() 
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    solve();
    return 0;
}