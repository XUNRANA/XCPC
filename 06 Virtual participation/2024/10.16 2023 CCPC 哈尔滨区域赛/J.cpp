#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[100010];
int ans,res;
int sz[100010];
void dfs(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}

//void dfs1(int u,int fa,int s)//删除边 
//{
//	for(auto v:g[u])
//	{
//		if(v==fa) continue;
//		if(s%2==1)//奇数=奇数+偶数
//		{
//			ans^=2;
//			if(ans==0) res++;
//			ans^=2;			
//		}
//		else
//		{
//			if(sz[v]%2==1)//偶数=奇数+奇数 
//			{
//				ans^=2;
//				ans^=1;
//				ans^=1;
//				if(ans==0) res++;
//				ans^=2;
//				ans^=1;
//				ans^=1; 
//			}
//			else //偶数=偶数+偶数 
//			{
//				ans^=2;
//				if(ans==0) res++;
//				ans^=2;
//			} 
//		}	
//		dfs1(v,u,s);
//	} 
//}


void dfs2(int u,int fa,int s)//删除点 
{ 
	int ans1=ans;
	
	if(s%2==1) ans1^=1;//消除整棵树的影响 
	else ans1^=2;
	
	for(auto v:g[u])
	{
		if(v==fa) continue;
		if(sz[v]%2==1) ans1^=1;//加上删除后儿子的贡献 
		else ans1^=2;
		dfs2(v,u,s);
	}
	int t=s-sz[u];//父亲的数量 
	
	if(fa!=0)//父亲的贡献（根节点没有父亲）  
	{
		if(t%2==1) ans1^=1;
		else ans1^=2;
	}
	
	if(ans1==0) res++;
}
 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>p;//根节点 
	for(int i=1;i<=n;i++) 
	{
		if(!sz[i]) 
		{
			dfs(i,0);
			p.push_back(i);
		}
	}
	
	ans=0;
	for(auto i:p)
	if(sz[i]%2==1) ans^=1;
	else ans^=2;
	
	
	//删除边等价于异或2 
	if(ans==2) res=m;
	else res=0;
	
	for(auto i:p) 
	{
		dfs2(i,0,sz[i]);//枚举删除点 
	}
	
	cout<<res<<"\n";

	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
