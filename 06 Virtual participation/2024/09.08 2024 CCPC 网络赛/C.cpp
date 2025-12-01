#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,ans,f[100010],sz[100010];
vector<int>g[100010];
void dfs(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	
	if(f[u])
	{
		ans+=sz[u]/2;
		if(sz[u]%2==1) 
		{
			ans++;
			if(fa!=-1&&f[fa]==0) f[fa]=1;
		}
		sz[u]=0;
	}
	else sz[u]++;
}
/*
4
3 1
1
1 2
1 3
4 1
1
1 2
1 3
1 4
5 2
3 1
1 2
1 3
3 4
3 5
4 4
1 4 2 3
1 3
1 4
3 2
*/
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear(),f[i]=sz[i]=0;
	for(int i=1;i<=m;i++)
	{
		int t;
		cin>>t;
		f[t]=1;
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		{
			ans=0;
			dfs(i,-1);
			cout<<ans<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
