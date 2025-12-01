#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,fa[200010],fa1[200010];
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
int find1(int x)
{
	return x==fa1[x]? x:fa1[x]=find1(fa1[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void merge1(int x,int y)
{
	fa1[find1(x)]=find1(y);
}
void solve()
{
	cin>>n>>m1>>m2;
	vector<pair<int,int>>a;
	for(int i=1;i<=m1;i++)
	{
		int u,v;
		cin>>u>>v;
		a.push_back({u,v});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m2;i++)
	{
		int u,v;
		cin>>u>>v;
		merge(u,v);
	}
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++) mp[find(i)].push_back(i);
	
	for(int i=1;i<=n;i++) fa1[i]=i;
	int cnt=0;
	for(auto i:a)
	{
		int u=i.first;
		int v=i.second;
		if(find(u)!=find(v)) cnt++;//Ò»¶¨ÒªÉ¾³ý 
		else merge1(u,v);
	}
	
	for(auto i:mp)
	{
		set<int>st;
		for(auto j:i.second) 
		{
			st.insert(find1(j));
		}

		cnt+=st.size()-1;
	}
	
	cout<<cnt<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
