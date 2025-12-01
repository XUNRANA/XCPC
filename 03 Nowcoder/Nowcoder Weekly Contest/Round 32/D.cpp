#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int>g[N];
int ans[N];
string s;
void dfs(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		ans[u]+=ans[v];
		if(s[v]=='1') ans[u]++;
	}
}
void solve()
{
	int n;
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

