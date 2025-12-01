#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 2e16
vector<int>g[200010];
int a[200010];
int f[200010];
int dp[200010][2][2];
void dfs(int u,int fa)
{
	int sum=0;
	int mx=-inf;
	int sum1=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sum+=max(dp[v][1][0],dp[v][0][0]);
		sum1+=max(dp[v][1][0],dp[v][0][1]);
		mx=max(mx,dp[v][0][1]-max(dp[v][1][0],dp[v][0][0]));
	}
	dp[u][0][0]=dp[u][0][1]=dp[u][1][0]=dp[u][1][1]=-inf;
	if(f[u])
	{
		dp[u][0][1]=sum+a[u];
	}
	else
	{
		dp[u][0][0]=sum+a[u];
		dp[u][0][1]=sum+a[u]+mx;
		dp[u][1][0]=sum1;
	}
}
void solve()
{
	int n,m;
    cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		g[i].clear();
		f[i]=0;
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=m;i++) 
	{
		int x;
		cin>>x;
		f[x]=1;
	}

	for(int x=1;x<=n;x++)
	{
		for(auto v:g[x]) 
		if(f[x]&&f[v])
		{
			cout<<"-1\n";
			return ;
		}
	}
	dfs(1,0);
	cout<<max(dp[1][1][0],dp[1][0][1])<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}