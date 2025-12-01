#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define int long long
int w[N],sz[N],n,u,v,ans,r=1e9;
vector<int>g[N];
void dfs(int u,int fa)
{
	sz[u]+=w[u];
	if(g[u].size()==2&&u!=1) r=min(r,sz[u]);
	if(g[u].size()==1&&u!=1) r=min(r,sz[u]);
	for(auto v:g[u])
	{
		if(v==fa) continue;
		sz[v]+=sz[u];
		dfs(v,u);
	}
}

void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i],ans+=w[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	if(g[1].size()==1) r=min(r,w[1]);
	cout<<ans-r-r<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
