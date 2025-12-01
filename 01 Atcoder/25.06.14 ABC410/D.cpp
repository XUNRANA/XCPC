#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<array<int,2>>g[1010];
int d[1010][1<<10];
int ans;
void dfs(int u,int st)
{
	for(auto v:g[u])
	{
		int nst=st^v[1];
		if(!d[v[0]][nst])
		{
			d[v[0]][nst]=1;
			dfs(v[0],nst);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	d[1][0]=1;
	dfs(1,0);
	for(int i=0;i<(1<<10);i++)
	if(d[n][i])	
	{
		cout<<i<<"\n";
		return ;
	}
	cout<<"-1\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
