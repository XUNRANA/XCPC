#include <bits/stdc++.h>
using namespace std;
#define int long long
int d[1010];//花费
int vt[1010];
int s[1010];//热度
int a[1010];
int n,m,ss,t;
vector<pair<int,int>>g[1010];
void solve() 
{
    cin>>n>>m>>ss>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
 
    for(int i=1;i<=n;i++) d[i]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d[ss]=0;
    a[ss]=a[t]=0;
    q.push({0,ss});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v1:g[u])
        {
            int v=v1.first;
            int w=v1.second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                s[v]=max(s[u],a[v]);
                q.push({d[v],v});
            }
            else if(d[v]==d[u]+w)
            {
                if(max(s[u],a[v])<s[v])
                {
                    s[v]=max(s[u],a[v]);
                    q.push({d[v],v});
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<d[i]<<"\n";
    // for(int i=1;i<=n;i++) cout<<s[i]<<"\n";
    if(d[t]==1e9) cout<<"Impossible\n";
    else cout<<d[t]<<" "<<s[t]<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}