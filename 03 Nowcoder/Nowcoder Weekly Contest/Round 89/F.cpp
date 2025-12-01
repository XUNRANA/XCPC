#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,f[N];
vector<int>g[N];
void dfs(int u,int fa) 
{
	for(auto v:g[u]) 
	{
		if(v==fa) continue ;
		dfs(v,u);
		if(!f[v]&&!f[u]) f[u]=-1;
	}
	if(f[u]==-1) 
	{
		f[fa]=1;
		ans++;
	}
}
/*

*/
int main() 
{
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
