#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[300010];
int p[300010],dfn[300010],vt[300010];
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
int cnt;
vector<pair<int,int>>ans;
void dfs()
{
	int u=p[cnt];
	vt[u]=1;
	cnt++;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vt[v]) continue;
		if(v==p[cnt]) dfs();
		else
		{
			ans.push_back({u,p[cnt]});
			dfs();
			i--;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cin>>p[i],dfn[p[i]]=i;
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end(),cmp);
	
	cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(!vt[p[i]])
		{
			dfs();
		}
	}
	
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
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
