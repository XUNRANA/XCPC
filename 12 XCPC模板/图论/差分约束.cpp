#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
#define inf 1000000000
int n,m,x,y,z,ans;
int d[N],vt[N],cnt[N],h[N];
vector<pair<int,int>>g[N];
bool spfa(int s)
{
	queue<int>q;
	for(int i=1;i<=n;i++) d[i]=inf;	
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
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n+1) return true;
				if(!vt[v]) q.push(v),vt[v]=1; 
			}
		}
	}
	return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[y].push_back({x,z});
	}
	for(int i=1;i<=n;i++) g[n+1].push_back({i,0});
	if(!spfa(n+1))
	{
		for(int i=1;i<=n;i++) cout<<d[i]<<" ";
		cout<<"\n";
	}
	else cout<<"NO\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
