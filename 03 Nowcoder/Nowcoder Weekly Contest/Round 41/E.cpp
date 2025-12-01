#include <bits/stdc++.h>
using namespace std;
int n,l,r,u,v,ans[100010];
vector<int>g[100010];
string s;
int dfs(int u,int fa)
{
	int res=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		res+=dfs(v,u);
	}
	if(res>1)
	{
		for(auto v:g[u])
		{
			if(v==fa) continue;
			if(s[v]=='W'&&ans[v]==1)
			{
				ans[v]=-1;
				res-=2;
			}
			if(res<2) break;
		}
	}
	
	if(s[u]=='R')
	{
		ans[u]=-res;
		res=0;
	}
	else
	{
		ans[u]=1;
		res++;
	}
	return res;
}

void solve()
{
	cin>>n>>l>>r>>s;
	s=" "+s;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
