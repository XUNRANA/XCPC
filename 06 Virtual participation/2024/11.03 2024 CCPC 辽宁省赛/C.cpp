#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
int sz[100010];
int f[100010];
vector<int>g[100010];
void dfs(int u,int fa)
{
	if(u&&g[u].size()==1)
	{
		f[u]=1;
		sz[u]=a[u];
		return ;
	}
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
/*
5
0 500
1 700
1 400
2 100
2 200

5
0 500
1 700
1 400
2 100
2 300
*/
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int fa;
		cin>>fa;
		g[fa].push_back(i);
		g[i].push_back(fa);
		cin>>a[i];
	}
	
	dfs(0,-1);
	
	vector<int>r1;
	vector<int>r2;
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			r1.push_back(a[i]);
			r2.push_back(sz[i]);
		}
	}
	sort(r1.begin(),r1.end());
	sort(r2.begin(),r2.end());
	for(int i=0;i<r1.size();i++)
	{
		if(r2[i]>r1[i])
		{
			cout<<"NO\n";
			return ;
		}
	}
	int sum=0;
	for(auto v:g[0]) sum+=sz[v];
	if(sum>2200) cout<<"NO\n";
	else cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
