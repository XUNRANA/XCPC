#include <bits/stdc++.h>
using namespace std;
#define int long long
double z,r;
int d[100010];
double val[100010];
vector<int>g[100010];
double ans;
void dfs(int u)
{
	if(!g[u].size()) ans+=val[u]*d[u];
	for(auto v:g[u]) 
	{
		val[v]=val[u]*(1-0.01*r);
		dfs(v);
	}
}
void solve()
{
	int n;
	cin>>n>>z>>r;
	val[0]=z;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		if(!c) cin>>d[i];
		else
		{
			while(c--)
			{
				int s;
				cin>>s;
				g[i].push_back(s);
			}
		} 
	}
	dfs(0);
	cout<<(int)ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

