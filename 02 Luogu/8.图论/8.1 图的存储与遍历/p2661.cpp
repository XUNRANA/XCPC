#include <bits/stdc++.h>
using namespace std;
int n,fa[200010],a[200010],t,ans=1e9,x,y;
vector<int>g[200010];
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void dfs(int u,int fa,int cnt)
{
	if(u==t)
	{
		ans=min(ans,cnt+1);
		return ;
	}
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,cnt+1);
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		x=find(i);
		y=find(t);
		if(x==y) dfs(i,0,0);
		else fa[y]=x;
		g[t].push_back(i);
		g[i].push_back(t);
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
