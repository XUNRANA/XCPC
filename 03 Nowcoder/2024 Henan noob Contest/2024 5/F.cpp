#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int n,m,x,y,z,dis1[N],vt1[N],dis2[N],vt2[N],ans;
vector<pair<int,int>>g1[N];
vector<pair<int,int>>g2[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g1[x].push_back({z,y});
		g2[y].push_back({z,x});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++) dis1[i]=1e18;
	dis1[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int w=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vt1[u]) continue;
		vt1[u]=1;
		for(auto i:g1[u])
		{
			int v=i.second;
			int w1=i.first;
			if(dis1[v]>w+w1)
			{
				dis1[v]=w+w1;
				q.push({w+w1,v});
			}
		}
	}
	
	
	for(int i=1;i<=n;i++) dis2[i]=1e18;
	dis2[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int w=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vt2[u]) continue;
		vt2[u]=1;
		for(auto i:g2[u])
		{
			int v=i.second;
			int w1=i.first;
			if(dis2[v]>w+w1)
			{
				dis2[v]=w+w1;
				q.push({w+w1,v});
			}
		}
	}
	ans=0;
	for(int i=2;i<=n;i++) ans+=dis1[i]+dis2[i];
	cout<<ans<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
