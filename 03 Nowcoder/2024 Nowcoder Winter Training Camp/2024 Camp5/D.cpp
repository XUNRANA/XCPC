#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300010
int n,s,t,u,v,w,ans,k,c[N],dp[N],dep[N];
vector<pair<int,int>>g[N];
vector<int>dis;
void dfs(int u,int fa)
{
	if(c[u]) return ;
	for(auto t:g[u])
	{
		int v=t.first;
		int w=t.second;
		if(v==fa) continue;
		dfs(v,u);
		if(c[v])
		{
			c[u]=1;//必经之路染红 
			dis.push_back(w);
		}
	}
}
void dfs1(int u,int fa)
{
	for(auto t:g[u])
	{
		int v=t.first;
		int w=t.second;
		if(v==fa||c[v]) continue;
		dep[v]=dep[u]+1;
		dp[dep[v]]=min(dp[dep[v]],w);
		dfs1(v,u);
	}
}
void solve()
{
	cin>>n>>s>>t;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	c[t]=1;
	dfs(s,0);
	for(int i=1;i<=n;i++)//除s外所有红色的相邻非红色点加入s的邻边 
	{
		if(c[i]&&i!=s)
		{
			for(auto t:g[i])
			{
				if(c[t.first]) continue;
				g[s].push_back(t);
			}
		}
	} 
	for(int i=0;i<=n;i++) dp[i]=1e9;
	dfs1(s,0); 
	sort(dis.begin(),dis.end());
	ans=0;
	k=dis.size();
	for(auto i:dis) ans+=i;
	dis.push_back(0); 
	while(dis.size()>1)
	{
		ans-=dis.back();
		dis.pop_back();
		cout<<ans<<" ";
	}
	for(int i=k;i<=n;i++)
	{
		ans=min(ans,dp[i-k]);
		cout<<ans<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
