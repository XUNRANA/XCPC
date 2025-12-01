#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,v;
vector<int>g[200010];
int sz[200010];
int a[200010];
int dp[200010][2];
void dfs(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs1(int u,int fa)
{
	if(g[u].size()==1)
	{
		if(u!=1)//根节点 
		{	
			dp[u][0]=a[u];
			dp[u][1]=0;
			return ;
		}
	}
	
	vector<int>p;
	for(auto v:g[u]) 
	{
		if(v==fa) continue;
		dfs1(v,u);
		if(sz[v]&1) p.push_back(dp[v][1]-dp[v][0]);
	}
	
	if(p.size())
	{
		sort(p.begin(),p.end(),greater<int>());
		dp[u][0]=dp[u][1]=0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			if(sz[v]%2==0) dp[u][1]+=max(dp[v][1],dp[v][0]);
			else dp[u][1]+=dp[v][0];				
		}
		
		if(p.size()%2==0)//偶数个奇数 
		{
			//一人一半 
			for(int i=0;i<p.size()/2;i++) dp[u][1]+=p[i];
			dp[u][0]=dp[u][1]+a[u];
		}
		else//奇数个奇数 
		{
			dp[u][0]=dp[u][1]+a[u];
			for(int i=0;i<p.size()/2;i++) dp[u][1]+=p[i];
			for(int i=0;i<p.size()/2+1;i++) dp[u][0]+=p[i]; 
		}
	}
	else//全为偶数 
	{
		dp[u][0]=a[u];
		dp[u][1]=0;
		for(auto v:g[u])
		{
			if(v==fa) continue;
			dp[u][1]+=dp[v][0];
			dp[u][0]+=dp[v][1];
		} 
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs1(1,0);
	cout<<dp[1][1]<<"\n";
}
/*

3
2
1 2
1 2
4
1 1 222 222
1 2
1 3
2 4
6
1 5 4 6 1 1
6 1
4 5
4 2
1 4
1 3
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
