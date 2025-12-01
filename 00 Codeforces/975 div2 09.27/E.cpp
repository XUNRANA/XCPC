#include <bits/stdc++.h>
using namespace std;
int n,u,v;
vector<int>g[500010];
vector<int>dep[500010];
int sz[500010];
int leaf[500010];
int vt[500010];
int deg[500010];
void dfs(int u,int fa,int d)
{
	sz[u]=1;
	dep[d].push_back(u);
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,d+1);
		sz[u]+=sz[v];
	}
	if(sz[u]==1&&u!=1) leaf[u]=1;
}
void solve()
{
	cin>>n;
	for(int i=0;i<=n+1;i++) g[i].clear(),dep[i].clear(),leaf[i]=vt[i]=deg[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0); 
	int s=0,ans=n;
	queue<int>q;
	for(int i=1;i<n;i++)//枚举深度 
	{
		int res=0;
		for(auto u:dep[i]) res+=sz[u]-1;//其子树全砍 
		ans=min(ans,res+s);
		for(auto u:dep[i]) if(leaf[u]) q.push(u);//当前深度的叶子节点全砍 
		while(!q.empty())//拓扑排序、消除叶子节点影响，防止影响下一个深度的答案 
		{
			int u=q.front();
			q.pop();
			if(vt[u]) continue;
			vt[u]=1;
			s++;
			for(auto v:g[u])
			{
				if(v==1) continue;
				if(--deg[v]<=1) q.push(v);
			}
		} 
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
