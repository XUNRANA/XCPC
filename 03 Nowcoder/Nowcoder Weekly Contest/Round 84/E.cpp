#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>g[100010];

int d[100010];
void dfs(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		d[u]+=d[v]+abs(u-v);
	}
}
int ans,res;
void dfs1(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		
		dfs1(v,u);
        ans=min(ans,abs(d[v]-(res-d[v]-abs(u-v))));
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	res=d[1];
	ans=1e18;
	dfs1(1,0);
	cout<<ans<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

