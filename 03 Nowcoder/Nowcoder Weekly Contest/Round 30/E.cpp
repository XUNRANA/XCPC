#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,dp[100010][2];
vector<int>g[100010];
void dfs(int u,int fa)
{
	if(g[u].size()==1&&fa!=0) dp[u][0]=dp[u][1]=1;
	int h=1,b=1;
    for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
        h=h*(dp[v][1]+dp[v][0])%P;
		b=b*(dp[v][1])%P;
	}
    dp[u][1]=h;
    dp[u][0]=b;
}
void solve()
{
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][1])%P;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

