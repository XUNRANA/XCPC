#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int f[400010];
int ans[200010];
void init()
{
	f[1]=1;
	for(int i=2;i<4e5;i++)
	{
		if(!f[i])
		for(int j=i+i;j<=4e5;j+=i) f[j]=1;
	}
}
int cnt=1;
void dfs(int u,int fa)
{
	if(fa!=0) while(!f[cnt-ans[fa]]) cnt++;
	ans[u]=cnt++;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cnt=1;
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
