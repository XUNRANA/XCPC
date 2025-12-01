#include <bits/stdc++.h>
using namespace std;
int n,q,u,v,c[200010];
vector<int>a;
vector<int>g[200010];
int dfs(int u1,int fa)
{
	if(u1==v)
	{
		set<int>s;
		for(auto i:a) s.insert(i);
		return s.size();
	}
	for(auto i:g[u1])
	{
		if(i==fa) continue;
		else
		{
			a.push_back(c[i]);
			return dfs(i,u1);
			a.pop_back();
		}
	}
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while(q--)
	{
		cin>>u>>v;
		a.clear();
		a.push_back(c[u]);
		cout<<dfs(u,0)<<"\n";
	}
	return 0;
}
/*
4 2
1 2 3 1
1 2
1 3
2 4
4 3
1 4
*/
