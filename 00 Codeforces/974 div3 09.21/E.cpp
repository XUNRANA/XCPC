#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010

int n,m,h,t,u,v,w;

int f[N];
int d[N];//1无马 
int dh1[N];//n有马 
int dn[N];//n无马 
int dhn[N];//n有马 
int vt[N];

vector<pair<int,int>>g[N];
void solve()
{
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++) g[i].clear();
	
	for(int i=1;i<=h;i++) cin>>f[i];
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	
	priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++) d[i]=1e18,vt[i]=0;
	q.push({0,1});
	d[1]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	
//	priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >q;
	for(int i=1;i<=n;i++) dn[i]=1e18,vt[i]=0;
	q.push({0,n});
	dn[n]=0;
	
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			if(dn[v]>dn[u]+w)
			{
				dn[v]=dn[u]+w;
				q.push({dn[v],v});
			}
		}
	}
	
	
	for(int i=1;i<=n;i++) dh1[i]=1e18,vt[i]=0;
	
	for(int i=1;i<=h;i++)
	{
		dh1[f[i]]=d[f[i]];
		q.push({dh1[f[i]],f[i]});
	}
	
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			w/=2;
			if(dh1[v]>dh1[u]+w)
			{
				dh1[v]=dh1[u]+w;
				q.push({dh1[v],v});
			}
		}
	}

	
	
	for(int i=1;i<=n;i++) dhn[i]=1e18,vt[i]=0;
	
	for(int i=1;i<=h;i++)
	{
		dhn[f[i]]=dn[f[i]];
		q.push({dhn[f[i]],f[i]});
	}
	
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			w/=2;
			if(dhn[v]>dhn[u]+w)
			{
				dhn[v]=dhn[u]+w;
				q.push({dhn[v],v});
			}
		}
	}
	
	int ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,max(min(d[i],dh1[i]),min(dn[i],dhn[i])));
	if(ans==1e18) ans=-1;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
