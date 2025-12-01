#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p 786433
int n,u,v,ans,a[200010];
vector<int>g[200010];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void dfs(int u,int fa,int r)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		ans=(ans+ksm(r&a[v],r&a[v]))%p;
		dfs(v,u,r&a[v]);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=0;
	for(int i=1;i<=n;i++) dfs(i,0,a[i]);
	cout<<ans<<"\n";
}
