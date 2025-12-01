#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>m;
vector<int>g[200010];
int n,u,v,ans[200010],ans1;
void dfs(int u,int fa)
{
	for(auto v:g[u])// 父节点u的子节点v的状态  如果时间戳（v，u）>（u，fa） 直接转移ans【v】=ans【u】  else ans[v]=ans[u]+1; 
	{
		if(v==fa) continue;
		if(m[{u,fa}]<m[{u,v}]) ans[v]=ans[u];
		else ans[v]=ans[u]+1;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	m.clear();
	for(int i=1;i<=n;i++) g[i].clear(),ans[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		m[{v,u}]=i;
		m[{u,v}]=i;	
	}
	m[{1,0}]=1e9;
	m[{0,1}]=1e9;
	ans1=0;
	dfs(1,0);
	for(int i=1;i<=n;i++) ans1=max(ans1,ans[i]);
	cout<<ans1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
