#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>g[200010];
int in[200010];
int sz[200010];
int ans;
void dfs(int u,int fa)
{
	if(in[u]&&g[u].size()==1)
	{
		sz[u]=1;
		return ;
	}
	vector<int>vt;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		vt.push_back(sz[v]);
	}
	sort(vt.begin(),vt.end());
	
	if(in[u]) sz[u]=vt[0]+1;
	else sz[u]=vt[0];
	
	for(int i=1;i<vt.size();i++) ans=max(ans,vt[i]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear(),in[i]=sz[i]=0;
	
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		g[fa].push_back(i);
		g[i].push_back(fa);
		in[i]++;
	}
	
	for(int i=1;i<=n;i++) 
	if(!in[i])
	{
		ans=0;
		dfs(i,-1);
		ans=max(ans,sz[i]);
		cout<<ans<<"\n";
		return ;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
