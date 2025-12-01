#include <bits/stdc++.h>
using namespace std;
int n,u,v;
vector<int>g[300010];
int p;
vector<pair<int,int>>ans;
int f=0;
void dfs(int u,int fa)
{
	vector<int>son;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		son.push_back(v);
	}
	
	if(son.size()%2==0)
	{
		for(int i=0;i<son.size();i+=2)
		{
			ans.push_back({son[i],son[i+1]});
		}
	}
	if(son.size()%2==1)
	{
		for(int i=0;i<son.size()-1;i+=2)
		{
			ans.push_back({son[i],son[i+1]});
		}
		p=son.back();
	}
	else p=u;
	
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		son.push_back(v);
		dfs(v,u);
	}
	
}


void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()%2==0)
		{
			cout<<i<<"\n";
			p=0;
			ans.clear();
			dfs(i,0);
			cout<<ans.size()<<"\n";
			for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
			return ;	
		}
	}
	cout<<"-1\n";
}
/*
1
6
1 2
2 3
2 4
1 5
5 6
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
