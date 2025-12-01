#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n,m,s,u,v;
vector<int>g[N];
int dep[N],fa[N][22],lg[N];
void dfs(int u,int f)
{
	fa[u][0]=f;//fa[u][i]表示u的2^i祖先 
	dep[u]=dep[f]+1;//深度 
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];//u的2^i祖先等于2^(i-1)祖先的2^(i-1)祖先 
	for(auto i:g[u])
	{
		if(i==f) continue;
		dfs(i,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u][lg[dep[u]-dep[v]]-1];//跳到同一层 
	if(u==v) return u;
	for(int k=lg[dep[u]]-1;k>=0;k--) if(fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];//跳到lca的下一层 
	return fa[u][0];
}
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(s,0);
	while(m--)
	{
		cin>>u>>v;
		cout<<lca(u,v)<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}