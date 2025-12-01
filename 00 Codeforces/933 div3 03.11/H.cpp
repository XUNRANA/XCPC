#include <bits/stdc++.h>
using namespace std;
int a,b,n,m,u,v,c,mx,ans;
vector<int>g[200010];
void solve()
{
	cin>>n>>m;
	map<int,set<int>>d;//d[i]集合表示哪些地铁线会经过地铁站i 
	set<int>s;//一共有哪些地铁线 
	mx=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>c;
		d[u].insert(c);
		d[v].insert(c);
		mx=max(mx,c);
	}
	cin>>a>>b;
	if(a==b) cout<<"0\n";
	else
	{
		for(int i=1;i<=mx;i++) g[i].clear();
		for(auto i:d)
		{
			vector<int>c;
			for(auto j:i.second) c.push_back(j);
			for(int i1=0;i1<c.size();i1++)
			{
				for(int j1=i1+1;j1<c.size();j1++)
				{
					g[c[i1]].push_back(c[j1]);
					g[c[j1]].push_back(c[i1]);
				}
			}
		}
			
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
