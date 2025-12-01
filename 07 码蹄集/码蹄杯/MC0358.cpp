#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int w[100010];
int vt[100010];
vector<int>g[100010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    for(int i=1;i<=n;i++) q.push({w[i],i});
    
    while(!q.empty())
    {
        int u=q.top()[1];
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v:g[u])
        {
            if(w[v]>w[u])
            {
                w[v]=w[u];
                q.push({w[v],v});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=w[i];
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++) cout<<w[i]<<" ";
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
