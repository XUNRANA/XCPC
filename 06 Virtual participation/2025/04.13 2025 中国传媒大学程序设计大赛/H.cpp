#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>g[100010];
int mx,mxu;
void dfs(int u,int fa,int d)
{
	if(d>mx)
	{
		mx=d;
		mxu=u;
	}
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,d+1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	dfs(mxu,0,0);
	if(mx>=3) cout<<"Yes\n";
	else cout<<"No\n";
	// cout<<mx<<" "<<mxu<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}  
