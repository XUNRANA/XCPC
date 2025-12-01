#include <bits/stdc++.h>
using namespace std;
#define N 300010
int n,m,q,op,x,y,fx,fy,fa[N],d[N],ans;
vector<int>g[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int dfs(int u,int fa)//求u所在连通块的直径ans 
{
	int d1=0,d2=0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		int t=dfs(v,u)+1;
		if(t>=d1) d2=d1,d1=t;
		else if(t>=d2) d2=t; 
	}
	ans=max(ans,d1+d2);
	return d1;
} 
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		fa[find(x)]=find(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	for(int i=1;i<=n;i++)//预处理连通块直径 
	{
		if(fa[i]!=i) continue;
		ans=0;
		dfs(i,0);
		d[i]=ans;
	}
	
	while(q--)
	{
		cin>>op;
		if(op==1) 
		{
			cin>>x;
			fx=find(x);
			cout<<d[fx]<<"\n";
		}
		else 
		{
			cin>>x>>y;
			fx=find(x);
			fy=find(y);
			if(fx==fy) continue;//跳过 
			int t=(d[fx]+1)/2+(d[fy]+1)/2+1;
			t=max(t,max(d[fx],d[fy]));//计算新的直径 
			fa[fx]=fy;//联通 
			d[fy]=t;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
