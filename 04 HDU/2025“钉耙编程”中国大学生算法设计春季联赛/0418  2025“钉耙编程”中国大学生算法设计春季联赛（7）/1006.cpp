#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<pair<int,int>>g[200010];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].insert({w,v});
		g[v].insert({w,u});
	}
	int ans=0;
	queue<int>q;
	for(int i=1;i<=n;i++) 
	if(g[i].size()==1) q.push(i);
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		int w=(*g[i].begin()).first;
		int v=(*g[i].begin()).second;
		g[i].clear();
		g[v].erase(g[v].find({w,i}));
		if(g[v].size()==1) q.push(v);
		ans+=w;
	}
	proirity_queue<array<int,3>,vector<array<int,3>>,less<array<int,3>>>pq;
	for(int i=1;i<=n;i++)
	if(g[i].size()>=2)
	{
		int w=(*g[i].rbegin()).first;
		int v=(*g[i].rbegin()).second;
		pq.push({w,u,v});
//		ans+=w;
//		cout<<w<<"??\n";
//		g[v].erase(g[v].find({w,i}));
	}
	while(!pq.empty())
	{
		int w=pq.top()[0];
		int u=pq.top()[1];
		int v=pq.top()[2];
		if(!g[u].find({w,v})) continue;
		if(vt[u]) continue;
		vt[u]=1;
		ans+=w;
		
		
	}
	cout<<ans<<"\n";
    
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
