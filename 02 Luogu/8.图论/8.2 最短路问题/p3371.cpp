#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,u,v,w;
int dis[100010],vt[100010];
vector<pair<int,int>>g[100010];
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++) dis[i]=(1ll<<31)-1;
	dis[s]=0;
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
			if(dis[v]>dis[u]+v1.second)
			{
				dis[v]=dis[u]+v1.second;
				q.push({dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

