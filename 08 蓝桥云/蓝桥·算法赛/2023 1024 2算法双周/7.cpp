#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,qr,w[N],ans[N];
vector<int>g[N];
vector<pair<int,int> >q[N];
map<int,int>cnt[N];//第一维深度，第二维点权，第三维记录是否存在
int son[N],sz[N];//重儿子 
int l[N],r[N],dfn,id[N],a[N],dep[N];
void dfs1(int u,int fa)//求重儿子 （sz最大的儿子） 
{
	son[u]=1;// 初始化子树大小
	l[u]=++dfn;// 记录DFS序的起点
	id[dfn]=u;// 记录DFS序对应的节点
	a[dfn]=w[u];// 记录DFS序对应的节点权值
	dep[u]=dep[fa]+1;// 记录节点深度
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs1(v,u);// 递归处理子节点
		son[u]+=son[v];// 更新子树大小
		if(son[v]>son[sz[u]]) sz[u]=v;// 更新重儿子
	}
	r[u]=dfn; // 记录DFS序的终点
}
void dfs2(int u,int fa,bool op)//启发式合并 
{
	for(auto v:g[u])
	{
		if(v==fa||v==sz[u]) continue;
		dfs2(v,u,false);
	}
	if(sz[u]) dfs2(sz[u],u,true);
	for(auto v:g[u])
	{
		if(v==fa||v==sz[u]) continue;
		for(int i=l[v];i<=r[v];i++) cnt[dep[id[i]]][a[i]]++;
	}
	cnt[dep[u]][w[u]]++;
	for(auto v:q[u])//离线查询 
	{
		int idd=v.second,k=v.first+dep[u];
		if(cnt[k].size()) ans[idd]=(*cnt[k].rbegin()).first;//反向为大 
	}
	if(!op) for(int i=l[u];i<=r[u];i++) cnt[dep[id[i]]].erase(a[i]);//轻儿子的部分删掉 
}
void solve()
{
	cin>>n>>qr;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	for(int i=1;i<=qr;i++)
	{
		int x,k;
		cin>>x>>k;
		q[x].push_back({k,i});
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=qr;i++) cout<<ans[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
