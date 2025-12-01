#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>>g[100010];
int n,m,u,v,w,f;
int cnt[31][2],vt[100010],val[100010];
void dfs(int u)
{
	if(!f) return ;
	vt[u]=1;
	for(int i=30;i>=0;i--) cnt[i][val[u]>>i&1]++;
	
	for(auto v1:g[u])
	{
		int v=v1.first;
		int w=v1.second;
		if(vt[v])
		{
			if((val[v]^val[u])!=w) 
			{
				f=0;
				return ;
			}
		}
		else
		{
			val[v]=val[u]^w;
			dfs(v);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	f=1;
	int res=0;
	for(int i=1;i<=n;i++) 
	{
		if(!vt[i]) 
		{
			for(int j=30;j>=0;j--) cnt[j][0]=cnt[j][1]=0;
			dfs(i);
			for(int j=30;j>=0;j--) res+=min(cnt[j][0],cnt[j][1])*(1<<j);
		}
	}
	if(!f) cout<<"-1\n";
	else cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
