#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define N 100010
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
int n,u,v;
vector<int>g[N];
int sz[N];
int sum[N];
int ans;
void dfs(int u,int fa)
{
	sz[u]=1;
	sum[u]=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		sum[u]=(sum[u]+sum[v])%P;
	}
	sum[u]=(sum[u]+sz[u]*sz[u]%P)%P;
}

void dfs1(int u,int fa)
{
	vector<int>vt;
	int s=0,res=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		vt.push_back(sum[v]);
		s=(s+sum[v])%P;
	}
	
	for(auto i:vt)
	{
		s=(s-i+P)%P;
		res=(res+s*i%P)%P;
	}
	
	ans=(ans+2*res%P)%P;//u-v1和u-v2。。。。。等等，u的儿子之间 
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		ans+=sz[v]*sz[v]%P*(n-sz[v])%P*(n-sz[v])%P;//u-v这条边 
		ans%=P;
		ans+=2*(sum[v]-sz[v]*sz[v]%P+P)%P*(n-sz[v])%P*(n-sz[v])%P;//u-v和v的子树内的边 
		ans%=P;
		dfs1(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	ans=0;
	dfs1(1,0);
	ans=4*ans%P*inv((n*n%P)*((n-1)*(n-1)%P)%P)%P;
	cout<<ans<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
