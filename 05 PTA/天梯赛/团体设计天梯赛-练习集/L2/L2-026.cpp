#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,f,r,mx;
vector<int>g[100010];
map<int,vector<int>>mp;
void dfs(int u,int d)
{
	mx=max(mx,d);
	mp[d].push_back(u);
	for(auto v:g[u]) dfs(v,d+1);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		if(f==-1) 
		{
			r=i;
			continue;
		}
		g[f].push_back(i);
	}
	dfs(r,1);
	cout<<mx<<"\n";
	sort(mp[mx].begin(),mp[mx].end());
	int f=0;
	for(auto i:mp[mx])
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

