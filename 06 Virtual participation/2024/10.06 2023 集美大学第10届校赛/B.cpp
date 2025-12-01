#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>g[100010];
vector<int>g1[100010];
int n,m;
int u,v,w;
int dis[100010];
int vt[100010];
int sg[100010];

int dfs(int u)
{
	if(sg[u]!=-1) return sg[u];
	set<int>st;
	for(auto v:g1[u]) st.insert(dfs(v));
	int now=0;
	for(auto i:st)
	{
		if(now==i) now++;
		else return sg[u]=now;
	}
	return sg[u]=now;
}

void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) g[i].clear(),g1[i].clear(),sg[i]=-1;
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++) dis[i]=1e18,vt[i]=0;
	dis[1]=0;
	q.push({0,1});
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
	for(int i=1;i<=n;i++) vt[i]=0;
	queue<int>q1;
	q1.push(n);
	while(!q1.empty())
	{
		int u=q1.front();
		q1.pop();
		
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			if(dis[v]+w==dis[u])
			{
				g1[v].push_back(u);
				q1.push(v);
			}
		}
	}
	sg[n]=0;//œ» ÷±ÿ∞‹
	dfs(1); 
	if(!sg[1]) cout<<"Little I is the winner.\n";
	else cout<<"Little M is the winner.\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
