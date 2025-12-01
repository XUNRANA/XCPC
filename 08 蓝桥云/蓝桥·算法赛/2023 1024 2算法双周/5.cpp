#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>g[100010];
int d[100010],n,u,v,w,c,ans;
void dfs(int u,int fa)
{
	for(auto i:g[u])
	{
		v=i.first;
		w=i.second;
		if(v==fa) continue;
		d[v]=d[u]+w;
		if(d[v]>d[c]) c=v;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		cin>>u>>v>>w;
		ans+=2*w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	} 
	dfs(1,0);
	d[c]=0;
	dfs(c,0);
	cout<<ans-d[c]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 




//#include <bits/stdc++.h>
//using namespace std;
//#define int long long 
//int mx[100010],ans[100010],s,n,u,v,w;
//vector<pair<int,int>>g[100010];
//void dfs(int u,int fa)
//{
//	int mx1=0,mx2=0;
//	for(auto i:g[u])
//	{
//		int v=i.first;
//		int w=i.second;
//		if(v==fa) continue;
//		dfs(v,u);
//		ans[u]=max(ans[u],ans[v]);
//		mx[u]=max(mx[u],mx[v]+w);
//		if(mx[v]+w>mx1) 
//		{
//			mx2=mx1;
//			mx1=mx[v]+w;
//		}
//		else if(mx[v]+w>mx2) mx2=mx[v]+w;
//	}
//	ans[u]=max(ans[u],mx1+mx2);
//}
//void solve()
//{
//	cin>>n;
//	for(int i=1;i<n;i++)
//	{
//		cin>>u>>v>>w;
//		s+=w;
//		g[u].push_back({v,w});
//		g[v].push_back({u,w});
//	}
//	dfs(1,0);
//	cout<<ans[1]+(s-ans[1])*2<<"\n";
//	
//}
//signed main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	int T=1;
//	//cin>>T;
//	while(T--) solve();
//} 
