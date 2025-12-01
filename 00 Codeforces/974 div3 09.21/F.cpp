#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,c,a[N],d[N][2];
vector<int>g[N];
void dfs(int u,int fa)
{
	
	d[u][0]=0;
	d[u][1]=a[u];
	//¸ù½Úµã 
	if(g[u].size()==1&&u!=1) return ; 
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		d[u][0]+=max(d[v][0],d[v][1]);
		d[u][1]+=max(d[v][0],d[v][1]-2*c);
	}
}
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans=max(d[1][0],d[1][1]);
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
