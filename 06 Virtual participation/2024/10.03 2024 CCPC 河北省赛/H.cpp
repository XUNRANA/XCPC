#include <bits/stdc++.h>
using namespace std;

#define N 500010
vector<int>g[500010];
int d[500010];

int v1[500010];
int v2[500010];

int dep[N],fa[N][22],lg[N];
int f1[N][22];
int f2[N][22];
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
void dfs1(int u,int f)
{
    
    f1[u][0]=min(v1[u],v1[f]);
    f2[u][0]=min(v2[u],v2[f]);

    for(int i=1;i<=20;i++) f1[u][i]=min(f1[u][i-1],f1[fa[u][i-1]][i-1]);
    for(int i=1;i<=20;i++) f2[u][i]=min(f2[u][i-1],f2[fa[u][i-1]][i-1]);

    for(auto v:g[u])
    {
        if(v==f) continue;
        dfs1(v,u);
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int>q;
    for(int i=1;i<=n;i++) d[i]=1e9;
    for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=k;i++)
    {
        int u;
        cin>>u;
        d[u]=0;
        q.push(u);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        if(d[v]>d[u]+1)
        {
            d[v]=d[u]+1;
            q.push(v);
        }
    }

    dfs(1,0);

    v1[0]=v2[0]=1e18;
    for(int i=1;i<=n;i++) 
    {
        v1[i]=3*d[i]-dep[i];
        v2[i]=3*d[i]+dep[i];
    }
    dfs1(1,0);

    // for(int i=1;i<=n;i++) cout<<i<<" "<<d[i]<<" "<<v1[i]<<" "<<v2[i]<<"\n";
    int q1;
    cin>>q1;
    while(q1--)
    {
        int x,y;
        cin>>x>>y;
        int l=lca(x,y);
        int dis=dep[x]+dep[y]-2*dep[l];
        int s11=dep[x]+dis;
        int s22=2*dis-dep[y];

        int s1=v1[x];
        int s2=v2[y];

        int ans=2*dis;
        // cout<<dis<<" "<<s1<<" "<<s2<<"?\n";

        // cout<<x<<" "<<y<<" "<<l<<"?\n";

        while(dep[x]>dep[l])
        {
            for(int i=20;i>=0;i--)
            if(dep[fa[x][i]]>=dep[l])
            {
                s1=min(s1,f1[x][i]);
                x=fa[x][i];
                break;
            }
        }
        
        while(dep[y]>dep[l])
        {
            for(int i=20;i>=0;i--)
            if(dep[fa[y][i]]>=dep[l])
            {
                s2=min(s2,f2[y][i]);
                y=fa[y][i];
                break;
            }
        }
        
        // cout<<x<<" "<<y<<" "<<l<<"!\n";

        cout<<min({s1+s11,s2+s22,ans})<<"\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
