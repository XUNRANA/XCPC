#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define inf 1000000000
int n,m,l,r,k;
int d[N],vt[N];
vector<pair<int,int>>g[N];
int spfa(int s,int t)
{
	queue<int>q;
	for(int i=0;i<=n;i++) d[i]=inf,vt[i]=0;
	d[s]=0;
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
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vt[v]) q.push(v),vt[v]=1; 
			}
		}
	}
	if(d[t]==inf) return -1;
	return d[t];
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++) g[i].clear();
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>k;
		g[l-1].push_back({r,k});
		g[r].push_back({l-1,-k});
	}
	for(int i=0;i<=n-1;i++) 
	{
		g[i].push_back({i+1,1});
		g[i+1].push_back({i,0});
	}
	
	spfa(n,0);
	int L=-d[0];
	spfa(0,n);
	int R=d[n];
	
	for(int i=max(1ll,L);i<=min(R,n);i++) cout<<i<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

