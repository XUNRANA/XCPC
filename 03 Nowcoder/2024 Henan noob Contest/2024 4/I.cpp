#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300010
vector<int>g[N];
int n,s,t,u,v,sz[N];
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
vector<int>path,res;
void dfs1(int u,int fa)
{
	if(u==t)
	{
		res=path;
		return ;
	}
	for(auto v:g[u])
	{
		if(v==fa) continue;
		path.push_back(v);
		dfs1(v,u);
		path.pop_back();
	} 
}
void solve()
{
	cin>>n>>s>>t;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	path.push_back(s);
	dfs1(s,0);
	int a1=res[1],b1=res[res.size()-2];
	dfs(s,0);
	int a=sz[s]-sz[a1];
	dfs(t,0);
	int b=sz[t]-sz[b1];
	cout<<a*b<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
