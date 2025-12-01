#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int f[N];
vector<pair<int,int>>g[N];
int dep[N],fa[N][22],lg[N];
int st[N][22][2];//最大值
void dfs(int u,int f)
{
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=1;i<=lg[dep[u]];i++) st[u][i][0]=max(st[u][i-1][0],st[fa[u][i-1]][i-1][0]);
    for(int i=1;i<=lg[dep[u]];i++) st[u][i][1]=max(st[u][i-1][1],st[fa[u][i-1]][i-1][1]);
	for(auto i:g[u])
	{
        int v=i.first;
        int w=i.second;
		if(v==f) continue;
        st[v][0][w&1]=w;
        st[v][0][(w&1)^1]=0;
		dfs(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u][lg[dep[u]-dep[v]]-1];
	if(u==v) return u;
	for(int k=lg[dep[u]]-1;k>=0;k--) if(fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
    return fa[u][0];
}

int query(int u,int v,int f)//返回u--lca与v---lca的路径中f(奇数、偶数)边权最大值
{

    if(dep[u]<dep[v]) swap(u,v);
    int res=0;
    for(int j=21;j>=0;j--) 
    if(dep[u]-(1<<j)>=dep[v]) 
    {
        res=max(res,st[u][j][f]);
        u=fa[u][j];
    }

    for(int j=21;j>=0;j--) 
    if(fa[u][j]!=fa[v][j]) 
    {
        res=max({res,st[u][j][f],st[v][j][f]});
        u=fa[u][j];
        v=fa[v][j];
    }

    if(u!=v) res=max({res,st[u][0][f],st[v][0][f]});
    return res;
}

int find(int x)
{
    return x==f[x]? x:f[x]=find(f[x]);
}
void merge(int x,int y)
{
    f[find(x)]=find(y);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,3>>a(m),b;
    for(int i=0;i<m;i++) cin>>a[i][1]>>a[i][2]>>a[i][0];
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++) 
    {
        f[i]=i,g[i].clear();
        for(int j=21;j>=0;j--) fa[i][j]=0;
    }
    int sum=0,cnt=0;
    for(auto i:a)
    {
        int w=get<0>(i);
        int u=get<1>(i);
        int v=get<2>(i);
        if(find(u)==find(v))
        {
            b.push_back({w,u,v});
            continue;
        }
        merge(u,v);
        cnt++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        sum+=w;
    }
    if(cnt!=n-1) 
    {
        cout<<"-1 -1\n";
        return ;
    }
    st[1][0][0]=st[1][0][1]=0;
    dfs(1,0);
    int ans1=sum;
    int ans2=1e18;
    for(auto i:b) 
    {
        int w=get<0>(i);
        int u=get<1>(i);
        int v=get<2>(i);
        int tt=query(u,v,(w&1)^1);
        if(tt) ans2=min(ans2,sum-tt+w);
    }
    if(ans2==1e18) ans2=-1;
    if(ans1&1) cout<<ans2<<" "<<ans1<<"\n";
    else cout<<ans1<<" "<<ans2<<"\n";
}               

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
