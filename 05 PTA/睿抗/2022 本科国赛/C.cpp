#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,p,u,v,s,t;
int a[100010];
vector<int>g[100010];
int vt[100010];
int ans[100010];
int d[100010];
void solve()
{
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>s>>t;
	for(int i=1;i<=n;i++) vt[i]=0,d[i]=1e9;
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
	p--;
	d[s]=0;
	ans[s]=(d[s]%k==p? a[s]:0);
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top()[1];
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g[u])
		{
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				ans[v]=ans[u]+(d[v]%k==p ? a[v]:0);
				q.push({d[v],v});
			}
			else if(d[v]==d[u]+1)
			{
				ans[v]=max(ans[v],ans[u]+(d[v]%k==p ? a[v]:0));
				q.push({d[v],v});
			}
		}
	}
	cout<<ans[t]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
