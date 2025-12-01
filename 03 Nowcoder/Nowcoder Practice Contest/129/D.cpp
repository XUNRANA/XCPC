#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[100010];
int n,m,k,a[100010],ans,s;
vector<int>p;
void dfs(int u,int fa)
{
	if(g[u].size()==1&&u!=n+1)
	{
		int s=0;
		for(int i=0;i<p.size();i++)
		{
			s+=p[i];
			if(i-m>=0) s-=p[i-m];
			ans=max(ans,s);
		}
		return ;
	}
	for(auto v1:g[u])
	{
		int v=v1.first;
		int w=v1.second;
		if(v==fa) continue;
		p.push_back(w);
		dfs(v,u);
		p.pop_back();
	}
}

void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
    g[n+1].clear();
	s=ans=0;
	for(int i=n,j=n;i>=1;i--)
	{
		s+=a[i];
		while(s>k) s-=a[j--];
		g[j+1].push_back({i,j-i+1});
		g[i].push_back({j+1,j-i+1});	
	}
	dfs(n+1,0);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
