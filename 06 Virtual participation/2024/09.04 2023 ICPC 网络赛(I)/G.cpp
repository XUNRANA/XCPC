#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define N 1000010
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
int n,u,v,fu,fv,fa[N],f[N],a[N],b[N],sz[N],dep[N];
vector<int>g[N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u,int fa)
{
	f[u]=fa;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans=1;
	for(int i=1;i<n;i++)
	{
		fu=find(a[i]);
		fv=find(b[i]);
		if(find(f[fu])==fv||find(f[fv])==fu)
		{
			ans=ans*inv(sz[fu]*sz[fv]%P)%P;
			if(dep[fu]>dep[fv])
			{
				sz[fv]+=sz[fu];
				fa[fu]=fv;
			}
			else
			{
				sz[fu]+=sz[fv];
				fa[fv]=fu;
			}
		}
		else ans=0;
	}
	cout<<ans<<"\n";
}

signed main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
