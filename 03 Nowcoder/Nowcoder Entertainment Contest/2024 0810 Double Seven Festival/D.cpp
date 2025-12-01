#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],fa[100010];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		fa[find(u)]=find(v);
	}
	
	map<int,int>mp[2];
	for(int i=1;i<=n;i++) mp[a[i]][find(i)]++;
	
	for(int i=1;i<=n;i++) cout<<mp[a[i]^1][find(i)]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
