#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v,w,a[100010],s,x;
vector< pair<int,int> >g[200010];
int vt[200010],dis[200010];
void dij(int s)
{
	for(int i=1;i<=2*n;i++) vt[i]=0,dis[i]=1e18;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,s});
	dis[s]=0;
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
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			} 
		}
	}
}
/*

4 5
3 2 7
4 1 6
3 4 2
2 1 2
3 1 8
27 27 9 8



6 8
3 4 12
6 5 18
3 6 20
4 1 11
3 1 10
4 2 19
2 6 10
6 1 15
47 30 57 6 71 93
*/
void solve()
{
	cin>>n>>m;
	s=2*n+1; 
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		
		g[u+n].push_back({v+n,w});
		g[v+n].push_back({u+n,w});
		
		
		g[u].push_back({v+n,0});
		
		g[v].push_back({u+n,0});
		
		g[u].push_back({u+n,0});
		
		g[v].push_back({v+n,0});
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		g[s].push_back({i,x});
	}
	dij(s);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dis[i+n]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
