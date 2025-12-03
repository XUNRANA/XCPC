#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300010
int n,m,k;
vector<array<int,2>> g[N];
int a[N];
int dep[N],fa[N][22],lg[N];
int val[N];
int d[N];
void dfs(int u,int f)
{
	fa[u][0]=f;//fa[u][i]表示u的2^i祖先 
	dep[u]=dep[f]+1;//深度 
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];//u的2^i祖先等于2^(i-1)祖先的2^(i-1)祖先 
	for(auto i:g[u])
	{
		if(i[0]==f) continue;
		val[i[0]]=i[1];
        dfs(i[0],u);
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
    for(auto i:g[u])
    {
        if(i[0]==f) continue;
        dfs1(i[0],u);
        d[u]+=d[i[0]];
    }
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++) cin>>a[i];

    for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);


	dfs(1,0);
    a[0]=1;
    for(int i=1;i<=m;i++)
    {
        int root=lca(a[i],a[i-1]);
        d[a[i]]++;
        d[a[i-1]]++;
        d[root]-=2;
    }    
    dfs1(1,0);

    // for(int i=1;i<=n;i++) cout<<val[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    // cout<<"\n";


    priority_queue<array<int,3>,vector<array<int,3>>> q;
    for(int i=1;i<=n;i++) q.push({((val[i]+1)/2)*d[i],val[i],d[i]});

    while(!q.empty()&&k>0)
    {
        auto t=q.top();
        q.pop();
        int reduce=t[0];
        int v=t[1];
        int cnt=t[2];
        k--;
        int nv=v/2;
        if(nv>0) q.push({((nv+1)/2)*cnt,nv,cnt});
    }

    int ans=0;
    while(!q.empty())
    {
        auto t=q.top();
        q.pop();
        int v=t[1];
        int cnt=t[2];
        ans+=1ll*v*cnt;
    }
    cout<<ans<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
