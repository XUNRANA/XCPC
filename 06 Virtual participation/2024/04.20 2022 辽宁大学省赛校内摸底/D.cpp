#include <bits/stdc++.h>
using namespace std;
int n,u,v,ans,index;
vector<int>g[200010];
int a[200010];
void dfs(int x,int fa)
{
	int c=0;
	for(auto i:g[x])
	{
		if(i==fa) continue;
		c++;
		while(c==a[x]||c==a[fa]) c++;
		a[i]=c;
		dfs(i,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=0;
	for(int i=1;i<=n;i++) 
	{
		if(g[i].size()+1>ans)
		{
			ans=g[i].size()+1;
			index=i;
		}
	}	
	cout<<ans<<"\n";
	a[index]=1;
	dfs(index,0);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve(); 
}
