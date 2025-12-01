#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 3010
#define inf 0x3f3f3f3f
int n,m,s,u,v,w;
int d[N],vt[N],cnt[N];
vector<pair<int,int>>g[N];
bool bellmanford(int s)//判负环 
{	
	d[s]=0;
	vt[s]=1;
	queue<int>q;
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
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return true;
				if(!vt[v]) q.push(v),vt[v]=1; 
			}
		}
	}
	return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) d[i]=inf,cnt[i]=vt[i]=0,g[i].clear();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(w>=0)
		{
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		else g[u].push_back({v,w});
	}
	cout<<(bellmanford(1)==0? "NO":"YES")<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
