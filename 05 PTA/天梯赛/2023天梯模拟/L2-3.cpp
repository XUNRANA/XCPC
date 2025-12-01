#include <bits/stdc++.h>
using namespace std;
int fa[100010];
int sz[100010];
int ans[100010];
int cnt;
int faa[10010];
vector<int>g[100010];
void dfs(int u)
{
	ans[u]=sz[u];
	for(auto v:g[u])
	{
		if(v==fa[u]) continue;
		dfs(v);
		ans[u]+=ans[v];
	}
}
void solve()
{
	int n,m;
	cin>>n>>m;
	map<string,int>mp;
	for(int i=1;i<=m;i++)
	{
		string a,b;
		cin>>a>>b;
		int f=0;
		for(auto i:a) if(isdigit(i)) f=1;
		if(f)
		{
			if(!mp.count(b)) mp[b]=++cnt;
			int id=stoi(a);
			faa[id]=mp[b];	
			sz[mp[b]]++;
		}
		else
		{
			if(!mp.count(a)) mp[a]=++cnt;
			if(!mp.count(b)) mp[b]=++cnt;
			g[mp[a]].push_back(mp[b]);
			g[mp[b]].push_back(mp[a]);
			fa[mp[a]]=mp[b];
		}
	}
	while(1)
	{
		char op;
		cin>>op;
		if(op=='T')
		{
			int id;
			string a;
			cin>>id>>a;
			sz[faa[id]]--;
			faa[id]=mp[a];
			sz[faa[id]]++;
		}
		else if(op=='Q')
		{
			string a;
			cin>>a;
			dfs(mp[a]);
			
			cout<<ans[mp[a]]<<"\n";
		}
		else break;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int T=1;
//	cin>>T;
	while(T--) solve();
}
