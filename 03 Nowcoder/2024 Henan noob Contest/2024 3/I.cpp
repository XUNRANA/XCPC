#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
int n,m,k,dis[N],vt[N];
vector<pair<int,int>>g[N],g0[N];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w,f;
		cin>>u>>v>>w>>f;
		if(f) 
		{
			g[u].push_back({w,v});
			g[v].push_back({w,u});
		}
		else 
		{
			g0[u].push_back({w,v});
			g0[v].push_back({w,u});
		}
	}
	for(int i=1;i<=n;i++) dis[i]=1e18;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto i:g[u])
		{
			int w1=i.first;
			int v=i.second;
			if(dis[v]>dis[u]+w1)
			{
				dis[v]=dis[u]+w1;
				q.push({dis[v],v});
			}
		}
	}
	int ans=1e18;
	ans=min(ans,dis[n]);
	int t=dis[k];
	
	for(int i=1;i<=n;i++) dis[i]=1e18,vt[i]=0;
	dis[k]=0;
	q.push({0,k});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto i:g[u])
		{
			int w1=i.first;
			int v=i.second;
			if(dis[v]>dis[u]+w1)
			{
				dis[v]=dis[u]+w1;
				q.push({dis[v],v});
			}
		}
		
		for(auto i:g0[u])
		{
			int w1=i.first;
			int v=i.second;
			if(dis[v]>dis[u]+w1)
			{
				dis[v]=dis[u]+w1;
				q.push({dis[v],v});
			}
		}
	}
	ans=min(ans,dis[n]+t);
    if(ans==1e18) ans=-1;
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
