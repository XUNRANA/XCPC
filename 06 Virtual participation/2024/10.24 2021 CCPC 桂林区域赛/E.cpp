#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[2010];
int dis[2010][2010];
int vt[2010];
int n,m,c,u,v,w;
void solve()
{
	cin>>n>>m>>c;
	int mi=1e9;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mi=min(mi,w);
		g[u].push_back({v,w});
	}
	if(mi>c)
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e9;
	
	for(int i=1;i<=n;i++)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
		for(int j=1;j<=n;j++) vt[j]=0;
		dis[i][i]=0;
		q.push({dis[i][i],i});
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
				if(dis[i][v]>dis[i][u]+w)
				{
					dis[i][v]=dis[i][u]+w;
					q.push({dis[i][v],v});
				}
			}
		}
	}
	mi=2e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mi=min(mi,dis[i][j]+dis[j][i]);
		}
	}
	if(c>=mi) cout<<"2\n";
	else cout<<"1\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
