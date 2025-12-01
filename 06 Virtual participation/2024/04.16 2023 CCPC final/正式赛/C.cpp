#include <bits/stdc++.h>
using namespace std;
vector<int>g[200010];
int n,m,u,v,ans[200010];
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) g[i].clear();
	vector<int>vt(n,0);
	for(int i=0;i<n-1;i++)
	{
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	g[n-1].push_back(0);
	g[0].push_back(n-1);	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<pair<int,int>>q;
	q.push({0,0});
	vt[0]=1;
	while(q.size())
	{
		u=q.front().first;
		int l=q.front().second;
		ans[u]=l;
		for(auto i:g[u])
		{
			if(vt[i]) continue;
			q.push({i,l^1});
			vt[i]=1;
		}
		q.pop();
	}
	for(int i=0;i<n;i++) if(ans[i]) cout<<"R";
	else cout<<"B";
	cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
