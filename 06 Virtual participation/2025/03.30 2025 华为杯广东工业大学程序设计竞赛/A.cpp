#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int f[N],a[N],d[N];
int n,m,k;
vector<pair<int,int>>g[N];
void solve() 
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) f[i]=0,g[i].clear();

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++) 
    {
        cin>>a[i];
        f[a[i]]=1;
    }
    if(k==1) cout<<"0\n";
    else
    {
        for(int i=1;i<=n;i++) d[i]=1e18;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int ans=0;
        d[a[1]]=0;
        q.push({d[a[1]],a[1]});
        while(!q.empty())
        {
            int w=q.top().first;
            int u=q.top().second;
            q.pop();
            if(f[u])
            {
                ans+=d[u];
                d[u]=0;
            }
            for(auto v1:g[u])
            {
                int v=v1.first;
                int w=v1.second;
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    q.push({d[v],v});
                }
            }
        }
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