#include <bits/stdc++.h>
using namespace std;
#define N 100010
int mxdep[N];// 保存以某个节点为根的子树的最大深度
int dp[N];// 保存以某个节点为根的子树的最长路径长度（包括该节点）
int ans[N];
vector<int>g[N];
void dfs(int u,int fa)
{
	int mx1=0,mx2=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);// 递归处理子节点
		mxdep[u]=max(mxdep[u],mxdep[v]+1); // 更新当前节点的最长路径长度
		dp[u]=max(dp[u],dp[v]); // 更新当前节点的最长路径长度
		if(mxdep[v]+1>mx1)
		{
			mx2=mx1;// 更新第二大的深度
			mx1=mxdep[v]+1;// 更新第一大的深度
		}
		else if(mxdep[v]+1>mx2) mx2=mxdep[v]+1;// 更新第二大的深度
	}
	dp[u]=max(dp[u],mx1+mx2);// 更新当前节点的最长路径长度
}

void dfs1(int u,int fa,int mx1,int mx2)
{
	multiset<int>s1,s2;
	s1.insert(0);
	s2.insert(0);
	for(auto v:g[u])
	{
		if(v==fa) continue;
		s1.insert(dp[v]);// 初始化集合，s1 保存所有子节点的 dp 值
		s2.insert(mxdep[v]+1);// 初始化集合，s2 保存所有子节点的 mxdep[v] + 1
	}
	s1.insert(mx1);
	s2.insert(mx2);
	ans[u]=*prev(s1.end());
	for(auto v:g[u])
	{
		if(v==fa) continue;
		s1.erase(s1.find(dp[v]));
		s2.erase(s2.find(mxdep[v]+1));
		// 计算删除当前节点后，子节点 v 能够继承的最长路径长度
		int t1=max(*prev(s1.end()),*prev(s2.end())+*prev(prev(s2.end())));
		 // 计算删除当前节点后，子节点 v 能够继承的最大深度
		int t2=*prev(s2.end())+1;
		dfs1(v,u,t1,t2);
		s1.insert(dp[v]);
		s2.insert(mxdep[v]+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs1(1,0,0,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
} 
/*
10
1 2
2 3
3 4
4 5
5 6
6 7
5 8
8 9
9 10
*/
