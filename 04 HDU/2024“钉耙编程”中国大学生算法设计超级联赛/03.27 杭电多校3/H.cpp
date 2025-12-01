#include <bits/stdc++.h>
using namespace std;
#define int long long
int vt[100100];
int d[100100];
vector<pair<int,int>>g[100100];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n+100;i++) 
    {
        g[i].clear();
        d[i]=1e18;
        vt[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) 
    {
        g[0].push_back({i,i*k});
        g[i].push_back({0,i*k});
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=20;j>=0;j--)
        if(i>>j&1)
        {
            g[i].push_back({j+1+n,i*k});
            g[j+1+n].push_back({i,(i^(1<<j))*k});
        }
    }


    for(int j=1;j<=20;j++)
    for(int i=j+1;i<=20;i++)
    {
        g[j+n].push_back({i+n,((1<<(j-1))+(1<<(i-1)))*k});
        g[i+n].push_back({j+n,((1<<(j-1))+(1<<(i-1)))*k});
    }


    d[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({d[1],1});
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
                // cout<<v<<" "<<d[u]+w<<"\n";
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    for(int i=2;i<=n;i++) cout<<d[i]<<" ";
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}