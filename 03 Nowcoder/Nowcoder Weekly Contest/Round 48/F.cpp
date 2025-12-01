#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,a[510][510],dis[400010],vt[400010];
int f[100001];
vector<int>g[100010];
vector<pair<int,int>>g1[400010];
void init()
{
	for(int i=2;i<=100000;i++)
	{
		if(!f[i])
		{	
			g[i].push_back(i);
			for(int j=i+i;j<=100000;j+=i)
			{
				f[j]=1;
				g[j].push_back(i);
			}	
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			if(i+1<=n) g1[cnt].push_back({cnt+m,1});
			if(j+1<=m) g1[cnt].push_back({cnt+1,1});
			for(auto k:g[a[i][j]])
			{
				g1[cnt].push_back({k+n*m,1});
				g1[k+n*m].push_back({cnt,0});
			}
		}
	}
	
	for(int i=1;i<=400000;i++) dis[i]=1e18;
	deque<int>q;
	q.push_back(1);
    dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g1[u])
		{
			int v1=v.first;
			int w=v.second;
			if(w+dis[u]<dis[v1])
			{
				dis[v1]=dis[u]+w;
				if(w) q.push_back(v1);
				else q.push_front(v1);
			}
		}
	}
 	cout<<dis[cnt]<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
