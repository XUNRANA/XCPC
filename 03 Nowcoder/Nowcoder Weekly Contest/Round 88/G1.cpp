#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N];
int L[N],R[N],val[N],a[N],fa[N];
int dfn;
//ST表，快速查询区间最大值/最小值 
int f[200010][22]; 
int query(int l,int r)
{
    if(l>r) return 0;
	int k=log2(r-l+1);//求区间长度 
	return max(f[l][k],f[r-(1<<k)+1][k]);//输出区间最大值 
}

void dfs1(int u,int fa)
{
    L[u]=++dfn;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs1(v,u);
    }
    R[u]=dfn;
}
void dfs2(int u,int fa)
{
    val[L[u]]=val[L[fa]]+a[u];
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs2(v,u);
    }
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        fa[i]=f;
        g[i].push_back(f);
        g[f].push_back(i);
    }
    dfs1(1,0);
    dfs2(1,0);
    
    for(int i=1;i<=n;i++) f[i][0]=val[i];//初始化区间[i,i]的最大值 
    for(int i=1;i<=21;i++) for(int j=1;j+(1<<i)-1<=n;j++)
    f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);//动态规划更新 
    
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=max({query(1,L[x]-1),query(R[x]+1,n),query(L[y],L[y])+query(L[x],R[x])-val[L[fa[x]]]});
        cout<<ans<<"\n";
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
