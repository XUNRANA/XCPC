#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,ans,fu,fv;
int fa[150010];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	map<pair<int,int>,int>f;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		if(u>v) swap(u,v);
		f[{u,v}]=1;
		fu=find(u);
		fv=find(v);
		if(fu!=fv) fa[fv]=fu;
	}
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i) continue;
		else mp[fa[i]].push_back(i);		
	}
	for(auto i:mp) mp[i.first].push_back(i.first);
	for(auto v:mp)
	{
		sort(v.second.begin(),v.second.end());
		for(int i=0;i<v.second.size();i++)
		{
			for(int j=i+1;j<v.second.size();j++)
			{
				if(!f.count({v.second[i],v.second[j]}))
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
}
