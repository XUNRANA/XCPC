#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int sz[100010];
int ans;
void dfs(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs1(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
        if(sz[v]%2==0) ans++;
		dfs1(v,u);
 	}
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n&1) cout<<"-1\n";
	else 
	{
		dfs(1,0);
		dfs1(1,0);
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
