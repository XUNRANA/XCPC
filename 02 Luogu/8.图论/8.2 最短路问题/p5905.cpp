#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 3010
#define inf 1000000000
int n,m,u,v,w,ans;
int d[N],vt[N],cnt[N],h[N];
vector<pair<int,int>>g[N];
bool spfa(int s)
{
	queue<int>q;
	for(int i=0;i<=n;i++) h[i]=inf;	
	h[s]=0;
	vt[s]=1;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vt[u]=0;
		for(auto v1:g[u])
		{
			int v=v1.first;
			int w=v1.second;
			if(h[v]>h[u]+w)
			{
				h[v]=h[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n+1) return true;
				if(!vt[v]) q.push(v),vt[v]=1; 
			}
		}
	}
	return false;
}
void dijkstra(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++) d[i]=inf,vt[i]=0;
	d[s]=0;
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
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++) g[0].push_back({i,0});
	if(spfa(0))
	{
		cout<<"-1\n";
		return ;
	}
	
	for(int u=1;u<=n;u++) 
	{
		for(auto &v:g[u])
		{
			v.second+=h[u]-h[v.first];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		ans=0;
		for(int j=1;j<=n;j++)
		if(d[j]==inf) ans+=j*inf;
		else ans+=j*(d[j]+h[j]-h[i]);
		cout<<ans<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

