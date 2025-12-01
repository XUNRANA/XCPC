#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[10010];
int mx,id;
int n,m,k,u,v,x;
void dij(int s)
{
    vector<int>d(n+1,1e9);
    vector<int>vt(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d[s]=0;
    q.push({d[s],s});
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
    mx=id=0;
    for(int i=1;i<=n;i++) 
    if(d[i]>mx&&d[i]!=1e9)
    {
        mx=d[i];
        id=i;
    }
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(k--)
    {
        cin>>x;
        dij(x);
        cout<<id<<"\n";
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