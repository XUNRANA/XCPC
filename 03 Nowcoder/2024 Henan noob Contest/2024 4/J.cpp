#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,r,q,u,v,x,k,l,fi[50],ans;
vector<int>g[N];
int dep[N],fa[N][30],lg[N];
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
void init()
{
	fi[1]=1;
	fi[2]=2;
	l=3;
	while(l)
	{
		fi[l]=fi[l-1]+fi[l-2];
		if(fi[l]>1e5) break;
		l++;
	}//1 2 3 5 8 13 21
}
void solve()
{
	cin>>n>>r>>q;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(r,0);
	while(q--)
	{
		cin>>x>>k;
		vector<int>res;
		for(int i=k;i<=l;i++) if(x+fi[i]<=n) res.push_back(x+fi[i]);
		if(res.size()==0) cout<<"0\n";
		else if(res.size()==1) cout<<res[0]<<"\n";
		else 
		{
			ans=lca(res[0],res[1]);
			for(int i=2;i<res.size();i++) ans=lca(ans,res[i]);
			cout<<ans<<"\n";
		}
	}
}
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
