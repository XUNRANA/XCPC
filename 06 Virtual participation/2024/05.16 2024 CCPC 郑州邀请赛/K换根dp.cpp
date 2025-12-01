#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
vector<int>g[N];
int no[N],a[N],ans,n;
int dfs1(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		no[u]+=dfs1(v,u)+(a[v]*2<a[u]);
	}
	return no[u];
}
void dfs2(int u,int fa)
{
	ans+=(no[u]==0);
	for(auto v:g[u])
	{
		if(v==fa) continue;
		no[v]=no[u]-(a[v]*2<a[u])+(a[u]*2<a[v]);
		dfs2(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		no[i]=0; 
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=0;
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--) solve();
}
