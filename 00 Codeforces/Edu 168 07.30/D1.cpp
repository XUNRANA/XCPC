#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
int n,fa,a[N],b[N];
vector<int>g[N];
void dfs(int u)
{
	int mi=2e9;
	for(auto v:g[u])
	{
		dfs(v);
		mi=min(mi,b[v]);
	}
	if(mi==2e9) 
	{
		b[u]=a[u];
		return ;
	}
	
	if(u==1)
	{
		a[u]+=mi;
		return ;
	}
	
	if(a[u]<mi) b[u]=a[u]+mi>>1;
	else b[u]=mi;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=0;
		g[i].clear();
	}
	for(int i=2;i<=n;i++)
	{
		cin>>fa;
		g[fa].push_back(i);
	}
	dfs(1);
	cout<<a[1]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
