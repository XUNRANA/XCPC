#include <bits/stdc++.h>
using namespace std;
int p[300010],vt[300010],dfn[300010];
vector<int>g[300010];
int cnt;
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
vector<pair<int,int>>ans;
void dfs(int u)
{
	vt[u]=1;
	cnt++;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vt[v]) continue;
		if(v!=p[cnt])
		{
			ans.push_back({u,p[cnt]});
			dfs(p[cnt]);
			i--;
		}
		else dfs(p[cnt]);
	}
}
void solve()
{
	int n,m;
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
	for(int i=1;i<=n;i++) if(!vt[p[i]]) dfs(p[i]);	
	
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
	cout<<"\n"; 
}
/*
6 6
1 3
1 4
2 3
3 4
3 6
5 6
1 2 3 4 5 6
 
8 8
2 8
3 8
5 6
1 6
6 3
8 7
2 3
4 3
1 8 7 5 4 2 3 6
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
