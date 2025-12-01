#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
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
int n;
vector<int>g[100];
int f[100];
int sz[100];
int is[100];
int c[100];
void dfs(int u)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==f[u]) continue;
		dfs(v);
		sz[u]+=sz[v];
	}
}
void dfs1(int u)
{
	is[u]=1;
	for(auto v:g[u])
	{
		if(v==f[u]) continue;
		dfs1(v);
	}
}
void solve()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>f[i];
		g[f[i]].push_back(i);
		g[i].push_back(f[i]);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	vector<int>p;
	for(int i=1;i<=n;i++) p.push_back(i);
	map<vector<int>,int>mp;
	int ans=0;
	do
	{
		for(int i=1;i<=n;i++) is[i]=0;
		vector<int>path;
		int res=1;
		int cnt=0;
		for(auto i:p)
		{
			if(is[i]) break;
			path.push_back(i);
			dfs1(i);
			cnt+=sz[i];
			res=res*ksm(c[path.size()],sz[i])%P;
		}
		int fx=0;
		for(int j=1;j<=n;j++) if(!is[j]) fx=1;
		if(fx==0) mp[path]=res;
	}while(next_permutation(p.begin(),p.end()));
	for(auto i:mp) ans=(ans+i.second)%P;
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
