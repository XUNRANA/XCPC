#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int n,w,ans,x,y,sumw,s;
int dd[200010],sum[200010];
void dfs(int u)
{
	sum[dd[u]]++;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(i+1<g[u].size()) dd[v]=g[u][i+1];
		else dd[v]=dd[u];
		dfs(v);
	}
}
void solve()
{
	cin>>n>>w;
	s=n;
	ans=n*w;
	sumw=w;
	for(int i=1;i<=n;i++) sum[i]=dd[i]=1,g[i].clear();
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		g[x].push_back(i);
	}
	dfs(1);
	sum[1]-=2;
	for(int i=1;i<n;i++) 
	{ 
		cin>>x>>y;
		sumw-=y;
		ans-=(s-2)*y;
		sum[dd[x]]--;
		sum[x]--;
		if(sum[x]==0)
		{
			ans-=sumw;
			s--;
		}
		if(sum[dd[x]]==0)
		{
			ans-=sumw;
			s--;
		}
		cout<<ans<<" ";
	}
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



