#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int a[100010];
int fa[100010][20];
int dep[100010];
int lg[100010];
void dfs(int u,int f)
{
    fa[u][0]=f;//fa[u][i]表示u的2^i祖先 
	dep[u]=dep[f]+1;//深度 
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];//u的2^i祖先等于2^(i-1)祖先的2^(i-1)祖先 
    a[u]+=a[f];
    for(auto v:g[u])
    {
        if(v==f) continue;
        dfs(v,u);
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1,0);
    // for(int i=1;i<=n;i++) cout<<a[i]<<"\n";
    
    int q;
    cin>>q;
    while(q--)
    {
        int m,x,y;
        cin>>m>>x>>y;
        int ff=lca(x,y);
        cout<<a[x]+a[y]-a[ff]<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
