#include <bits/stdc++.h>
using namespace std;
#define int long long
int sz[100010];
int vt[100010];
int s,t,n;
int ans;
vector<array<int,3>>g[100010];
vector<int>path;
int mx;
void dfs1(int u,int fa)
{
	sz[u]=0;
	for(auto v1:g[u])
	{
		int v=v1[0];
		int w=v1[2];
		if(v==fa||vt[v]) continue;
		dfs1(v,u);
		sz[u]+=max(0ll,w+sz[v]);
	}
}
void dfs(int u,int fa,int sum)
{
	if(u==t)
	{
		ans=sum;
		for(auto i:path) vt[i]=1;
		for(auto i:path) 
		{
			dfs1(i,0);
			ans+=sz[i];
		}
		return ;
	}
	for(auto v1:g[u])
	{
		int v=v1[0];
		int w=v1[1];
		if(v==fa) continue;
		path.push_back(v);
		dfs(v,u,sum+w);
		path.pop_back();
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear(),vt[i]=0;
	for(int i=1;i<n;i++) 
	{
		int u,v,p,q;
		cin>>u>>v>>p>>q;
		g[u].push_back({v,p,p+q});
		g[v].push_back({u,q,p+q});
	} 
	cin>>s>>t;
	path.clear();
	path.push_back(s);
	dfs(s,0,0);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
