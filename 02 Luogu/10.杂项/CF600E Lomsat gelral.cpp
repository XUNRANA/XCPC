#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,c[N],sz[N],s[N];
vector<int>g[N];
void dfs1(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(!s[u]||sz[v]>sz[s[u]]) s[u]=v;
	}
}
void dfs2(int u,int fa,int keep)
{
	for(auto v:g[u])
	{
		if(v==fa||v==s[u]) continue;
		dfs2(v,u,0);//暴力统计轻边的贡献，消除影响 
	}
	if(s[u]) dfs2(s[u],u,1);
	
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0,0,0);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
