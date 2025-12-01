#include <bits/stdc++.h>
using namespace std;
int n,u,v,w;
vector<pair<int,int>>g[100010];
int p[100010];
void dfs(int u,int fa)
{
	for(auto v1:g[u])
	{
		int v=v1.first;
		int w=v1.second;
		if(v==fa) continue;
		p[v]=p[u]^w;
		dfs(v,u);
	}
}
int ans,nex[30*100010][2],cnt;
void insert(int x)
{
	int now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(!nex[now][t]) nex[now][t]=++cnt;
		now=nex[now][t];
	}
}
void query(int x)
{
	int res=0,now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(nex[now][!t])
		{
			res|=1<<i;
			now=nex[now][!t];
		}
		else now=nex[now][t];
	}
	ans=max(ans,res);
}
void solve()
{
	// cin>>n;
    scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
        scanf("%d %d %d",&u,&v,&w);
		// cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) insert(p[i]);
	for(int i=1;i<=n;i++) query(p[i]);
	cout<<ans<<"\n"; 
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
