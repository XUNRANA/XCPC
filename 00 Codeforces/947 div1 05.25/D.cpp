#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,a,b,u,v;
vector<int>g[N];
int f[N],dep[N];
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
	cin>>a>>b;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[a]=0;
	dfs(a,0);
	int cnt=0;
	while(dep[b]>cnt)
	{
		b=f[b];
		cnt++;
	}
	dep[b]=0;
	dfs(b,0);
	int mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,dep[i]);
	cout<<cnt+2*(n-1)-mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
