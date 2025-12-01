#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int n,dp[N][2],ans;
vector<pair<int,int>>g[N];
void dfs(int u,int fa)
{
    int s=0,mx=0;
	for(auto i:g[u])
	{
		int w=i.first;
		int v=i.second;
		if(v==fa) continue;
		dfs(v,u);
        s+=max(dp[v][0],dp[v][1]);
	}
    dp[u][0]=s;
    for(auto i:g[u])
    {
        int w=i.first;
		int v=i.second;
		if(v==fa) continue;
        dp[u][1]=max(dp[u][1],s-max(dp[v][0],dp[v][1])+dp[v][0]+w);
    }
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	dfs(1,0);
    //for(int i=1;i<=n;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    cout<<max(dp[1][0],dp[1][1])<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
