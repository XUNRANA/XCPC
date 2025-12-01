#include <bits/stdc++.h>
using namespace std;
#define N 200010
vector<pair<int,int>>g[N];
int fa[N],s[2];
double d[N];
void dfs(int u,int p)
{
	d[u]=1.0*s[1]/(s[0]+s[1]);
	double r=1-p;
	for(auto v:g[u])
	{
		if(fa[u]==v.first) continue;
		fa[v.first]=u;
		s[v.second]++;//个数++ 
		dfs(v.first,1-p);
		s[v.second]--;//个数-- 
		if(p==1) r=max(r,d[v.first]);
		else r=min(r,d[v.first]);
	}
	if(u==1) d[u]=r;
	else if(g[u].size()>1) d[u]=min(d[u],r);
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) g[i].clear(); 
	for(int i=1;i<n;i++)
	{
		int x,y,k;
		cin>>x>>y>>k;
		g[x].push_back({y,k});
		g[y].push_back({x,k});
	}
	dfs(1,1);
	printf("%.12f\n",d[1]); 
    //for(int i=1;i<=n;i++) printf("%.12f\n",d[i]); 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}