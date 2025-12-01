#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,z,fa[100010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	map<pair<int,int>,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		if(x>y) swap(x,y);
		if(y>z) swap(y,z);
		if(x>y) swap(x,y);
		mp[{x,y}].push_back(i);
		mp[{y,z}].push_back(i);
		mp[{x,z}].push_back(i);
	}
	for(auto i:mp)
	{
		int p=0;
		for(auto j:i.second)
		{
			if(p) merge(j,p);
			p=j;
		}
	}
	map<int,int>cnt;
	for(int i=1;i<=n;i++) cnt[find(i)]++;
	vector<int>v;
	for(auto i:cnt) v.push_back(i.second);
	cout<<v.size()<<"\n";
	sort(v.begin(),v.end());
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
/*
1
7
1001 1002 1003
1001 1002 1004
1001 1003 1004
1002 1003 1004
1006 1005 1001
1006 1005 1002
1006 1005 1003
*/
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
/*
6
2 0 5 9 22 30
*/
