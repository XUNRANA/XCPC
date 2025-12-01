#include <bits/stdc++.h>
using namespace std;
int n,c0,c1,c,ans,u,v,cnt;
vector<int>g[100010];
string s;
void dfs(int u,int fa)
{
	if(g[u].size()==1&&u!=1)
	{
		if(s[u]=='?') c++;
		else if(s[u]=='1') c1++;
		else c0++;
	}
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>s;
	s="."+s;
	c=c1=c0=ans=cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='?') cnt++;
	dfs(1,0);

	if(s[1]=='?')
	{
		if(c0==c1)
		{
			ans+=c0;
			int t=cnt-c-1;
			if(t&1) ans+=max(c-c/2,c/2);
			else ans+=min(c-c/2,c/2);
		}
		else ans=max(c0,c1)+c/2;
	}
	else
	{
		if(s[1]=='1') ans+=c0;
		else ans+=c1;
		ans+=(c+1)/2;
	}
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
