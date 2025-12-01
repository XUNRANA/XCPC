#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>g[1010];
int a[1010];
int d[1010];
int mx[1010];
int vt[1010];
int pre[1010];
void solve()
{
	int n,m,s,t,u,v,w;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++) d[i]=1e18,vt[i]=0;
	d[s]=0;
	a[s]=a[t]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
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
				mx[v]=max(mx[u],a[v]);
				q.push({d[v],v});
			}
			else if(d[v]==d[u]+w)
			{
				if(max(mx[u],a[v])<mx[v])
				{
					mx[v]=max(mx[u],a[v]);
					q.push({d[v],v});
				}
			}
		}
	}
    if(d[t]==1e18) cout<<"Impossible\n";
	else cout<<d[t]<<" "<<mx[t]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
