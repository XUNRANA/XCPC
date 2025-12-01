#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,u,v,vt[100010],dp[100010];
vector<int>g[100010];
map<pair<int,int>,int>mp,mpi;
void dfs(int u,int c)
{
	if(u==n)
	{
        for(auto i:mp) 
        if(!i.second) dp[mpi[i.first]]=min(dp[mpi[i.first]],c);
	}
	for(auto v:g[u])
	{
        int v1=min(u,v),u1=max(u,v);
		if(mp[{v1,u1}]) continue;
		mp[{v1,u1}]=1;
		dfs(v,c+1);
		mp[{v1,u1}]=0;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1e9;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
        if(u>v) swap(u,v);
        mp[{u,v}]=0;
        mpi[{u,v}]=i;
	}
	dfs(1,0); 
	for(int i=1;i<=n;i++) cout<<(dp[i]==1e9? -1:dp[i])<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
