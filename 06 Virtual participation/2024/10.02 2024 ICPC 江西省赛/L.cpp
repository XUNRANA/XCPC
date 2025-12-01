#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,T,u,v,w;
int dis[100010][16];
int vt[100010],a[100010];
int p[16],l[16],r[16];
int f[100010],ans[100010];
vector<pair<int,int> >g[100010];

void dij(int s,int i)
{
	for(int j=1;j<=n;j++) dis[j][i]=1e18,vt[j]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int> >>q;
	dis[s][i]=0;
	q.push({0,s});
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
			if(dis[v][i]>dis[u][i]+w)
			{
				dis[v][i]=dis[u][i]+w;
				q.push({dis[v][i],v});
			}
		}
	}
}

void solve()
{
	cin>>n>>m>>k>>T;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++) cin>>p[i]>>l[i]>>r[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++)
	{
		dij(p[i],i);
		f[l[i]]+=(1ll<<i);
		f[r[i]+1]-=(1ll<<i);
	}
	
	for(int i=1;i<=T;i++) f[i]+=f[i-1];
	for(int i=1;i<=T;i++)
	{
		if(f[i]==0) 
		{
			ans[i]=-1;
			continue;
		}
		if(f[i]==f[i-1])
		{
			ans[i]=ans[i-1];
			continue;
		}
		vector<int>res(n+1,1e18);
		for(int j=1;j<=k;j++)
		{
			if(f[i]>>j&1)
			{
				for(int l=1;l<=n;l++) res[l]=min(res[l],dis[l][j]*a[l]);
			}
		}
		ans[i]=0;
		for(int j=1;j<=n;j++) ans[i]+=res[j];
	}
	for(int i=1;i<=T;i++) cout<<ans[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
