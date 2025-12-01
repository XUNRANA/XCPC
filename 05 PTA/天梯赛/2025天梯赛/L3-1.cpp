#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,3>>g[510];
int d[510];
int vt[510];
int f[510];
int b,n,m,k;
void dij(int s)
{
	for(int i=1;i<=n;i++) d[i]=1e18,vt[i]=0,f[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	d[s]=0;
	q.push({d[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g[u])
		{
			if(d[v[0]]>d[u]+v[1])
			{
				d[v[0]]=d[u]+v[1];
				f[v[0]]=f[u]+v[2];
				q.push({d[v[0]],v[0]});
			}
			else if(d[v[0]]==d[u]+v[1]) f[v[0]]=max(f[v[0]],f[u]+v[2]);
		}
	}
}
void solve()
{
	cin>>b>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,p,q;
		cin>>u>>v>>p>>q;
		g[u].push_back({v,p,q});
		g[v].push_back({u,p,q});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		dij(x);
//		for(int j=1;j<=n;j++) cout<<d[j]<<" ";
//		cout<<"\n";
//		
//		for(int j=1;j<=n;j++) cout<<f[j]<<" ";
//		cout<<"\n";
		int f1=0;
		int mx=0;
		map<int,vector<int>>mp;
		for(int j=1;j<=n;j++) 
		if(j!=x&&d[j]<=b) 
		{
			mp[f[j]].push_back(j);
			mx=max(mx,f[j]);
			if(f1) cout<<" ";
			cout<<j;
			f1=1;
		}
		if(!f1)
		{
			cout<<"T_T\n";
			continue;
		}
		cout<<"\n";
		
		
		f1=0;
		for(auto j:mp[mx])
		{
			if(f1) cout<<" ";
			cout<<j;
			f1=1;
		}
		cout<<"\n";
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
