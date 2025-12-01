#include <bits/stdc++.h>
using namespace std;
#define N 300010
int p[N],n,q,cnt,good[N],f[N];
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

void ck(int i)
{
	if(i<2||i>n) return ;
	cnt-=good[i];
	good[i]=(f[p[i]]==p[i-1])||(lca(p[i],p[i-1])==f[p[i]]);
	//good[i]=(lca(p[i],p[i-1])==p[i-1])||(lca(p[i],p[i-1])==f[p[i]]);  不能AC 
	cnt+=good[i];
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i),g[i].clear();
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		f[i]=x;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++) cin>>p[i],good[i]=0;
	dfs(1,0);
	cnt=0;
	for(int i=2;i<=n;i++) ck(i); 
	//cout<<cnt<<"\n"; 
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		swap(p[x],p[y]);
		ck(x);
		ck(x+1);
		ck(y);
		ck(y+1);
		if(cnt==n-1) cout<<"YES\n";
		else cout<<"NO\n";
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

