#include <bits/stdc++.h>
using namespace std;

vector<int>g[100010];
int d[100010];
int vt[100010];
int f[100010];
void dfs(int u)
{
	for(auto v:g[u]) 
	{
		d[v]=d[u]+1;
		dfs(v);
	}
}
void solve()
{
	int n,m,x,rt;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]==-1) rt=i;
		else g[f[i]].push_back(i); 
	}
	dfs(rt);
	vt[rt]=1;
	int deep=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		deep=max(deep,d[x]);
		while(!vt[x])
		{
			ans+=2;
			vt[x]=1;
			x=f[x];
		}
		cout<<ans-deep<<"\n";
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

