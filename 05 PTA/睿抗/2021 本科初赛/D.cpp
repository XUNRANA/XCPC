#include <bits/stdc++.h>
using namespace std;
int n,m,d,u,v;
vector<int>g[50010];
int fa[50010];
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int is[50010];
int c[1010];
int ans[1010];
int ql;
vector<pair<int,int>>q[1010];
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++) is[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=d;i++)
	{
		cin>>c[i]>>ql;
		is[c[i]]=1;
		while(ql--)
		{
			cin>>u>>v;
			q[i].push_back({u,v});
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) 
	if(!is[i])
	{
		for(auto v:g[i])
		{
			if(!is[v])
			{
				merge(i,v);
			}
		}
	}
	for(int i=d;i>=1;i--)
	{
		int cnt=0;
		for(auto j:q[i])
		{
			if(find(j.first)!=find(j.second)) cnt++;
		}
		ans[i]=cnt;
		
		is[c[i]]=0;
		for(auto v:g[c[i]])
		{
			if(!is[v])
			{
				merge(v,c[i]);
			}
		}
	}
	for(int i=1;i<=d;i++) cout<<ans[i]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

