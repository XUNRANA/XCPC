#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,fa[200010],p[200010];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	fa[find(u)]=find(v);	
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) 
	{
		cin>>p[i];
		merge(p[i],i);
	}
	string s;
	cin>>s;
	s=" "+s;
	map<int,int>mp[2];
	for(int i=1;i<=n;i++) mp[s[i]-'0'][find(i)]++;
	for(int i=1;i<=n;i++)
	cout<<mp[0][find(i)]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

