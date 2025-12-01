#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,l,r,m,f,ans,a[200010];
vector<int>g[200010];
void dfs(int u,int s)
{
	if(s>2e9) f=0;
	if(g[u].size()==0) if(a[u]<s) f=0;
	for(auto v:g[u]) dfs(v,s+max(0ll,s-a[u]));
}
int ck(int x)
{
	f=1;
	for(auto v:g[1]) dfs(v,x-a[1]);
	return f;
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
	for(int i=2;i<=n;i++) 
	{ 
		cin>>p;
		g[p].push_back(i);
	}
	int l=a[1],r=2e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) ans=m,l=m+1;
		else r=m-1;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
