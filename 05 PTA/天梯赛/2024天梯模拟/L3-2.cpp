#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[100010];
int p[100010];
vector<int>g[100010];
int dp[100010][3];
//0: 0比1多1 
//1: 1比0多1 
//2: 0和1相等 
int son[100010];

void dfs(int u,int fa)
{
	dp[u][0]=dp[u][1]=dp[u][2]=1e18;
	son[u]=1;
	int sz=1;
	int sum=(c[u]? 0:p[u]);
	vector<int>vec;
	vec.push_back((c[u]? p[u]:-p[u]));
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		son[u]+=son[v]; 
		if(son[v]%2==0) sum+=dp[v][2];
		else 
		{
			sz++;
			sum+=dp[v][1];
			vec.push_back(dp[v][0]-dp[v][1]);	
		}
	}
	sort(vec.begin(),vec.end());
	if(son[u]%2==0)
	{
		for(int i=0;i<sz/2;i++) sum+=vec[i];
		dp[u][2]=sum;
	}
	else
	{
		for(int i=0;i<sz/2;i++) sum+=vec[i];
		dp[u][1]=sum;
		dp[u][0]=sum+vec[sz/2];
	}
}

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>c[i]>>p[i]>>k;
		while(k--)
		{
			int u;
			cin>>u;
			g[i].push_back(u);
			g[u].push_back(i);
		}
	}
	dfs(1,0);
	cout<<min({dp[1][0],dp[1][1],dp[1][2]});
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
