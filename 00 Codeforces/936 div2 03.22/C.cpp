#include <bits/stdc++.h>
using namespace std;
vector<int>g[100010];
int s[100010];
int n,x,y,lim,tot,k,l,r,m,u,v;
void dfs(int u,int fa)
{
	s[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		s[u]+=s[v];
	}
	if(s[u]>=lim&&tot>0)
	{
		s[u]=0;
		tot--;
	} 
}

int ck(int x)
{
	lim=x,tot=k;
	dfs(1,0);
	return s[1]>=x;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) s[i]=0,g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	l=1,r=n/(k+1);
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<l-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
