#include <bits/stdc++.h>
using namespace std;
int n,u,v,w,cnt,ans,s[100010];
vector<pair<int,int>>g[100010];
int nex[30*100010][2];
void insert(int x)//插入trie树 
{
	int now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(!nex[now][t]) nex[now][t]=++cnt;
		now=nex[now][t];
	}
}
void query(int x)//查找与x异或最大的 
{
	int res=0,now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(nex[now][!t])//有反向走反向 
		{
			res|=1<<i;
			now=nex[now][!t];
		}
		else now=nex[now][t];
	}
	ans=max(ans,res);//找最大 
}
void dfs(int u,int fa)
{
	for(auto t:g[u])
	{
		int v=t.first;
		int w=t.second;
		if(v==fa) continue;
		s[v]=s[u]^w;//s[v]为根节点1号到v的路径异或和 
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) insert(s[i]);
	for(int i=1;i<=n;i++) query(s[i]);
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}