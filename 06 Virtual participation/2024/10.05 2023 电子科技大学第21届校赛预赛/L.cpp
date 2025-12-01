#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int p[100010],n,u,v;
void dfs(int u,int fa)
{
	p[u]=fa;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(n,0);
	for(int i=1;i<n;i++) cout<<p[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
/*
5
 1 2
 1 3
 2 4
 2 5
*/
