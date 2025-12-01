#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,dis[1010][1010],vt[1010][1010];
char a[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
vector<pair<int,int>>g[1000010];
void solve()
{
	cin>>n>>m;
	vector<pair<int,int>>v;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='*') v.push_back({i,j});
		}
	}
	for(int i=0;i<v.size();i++)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[i][j]=1e9,vt[i][j]=0;
		int x=v[i].first,y=v[i].second;
		dis[x][y]=0;
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
		q.push({0,{x,y}});
		while(!q.empty())
		{
			x=q.top().second.first;
			y=q.top().second.second;
			q.pop();
			if(vt[x][y]) continue;
			vt[x][y]=1;
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='#') continue;
				if(dis[nx][ny]>dis[x][y]+1)
				{
					dis[nx][ny]=dis[x][y]+1;
					q.push({dis[nx][ny],{nx,ny}});
				}
			}
		}
		for(int j=0;j<v.size();j++) 
		{
			if(j==i) continue;
			int x1=v[j].first;
			int y1=v[j].second;
			if(dis[x1][y1]!=1e9) g[i].push_back({dis[x1][y1],j});
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,0});
	int ans=0;
	vector<int>f(v.size());
	while(!q.empty())
	{
		int w=q.top().first;
		int u=q.top().second;
		q.pop();
		if(f[u]) continue;
		f[u]=1;
		ans+=w;
		for(auto v:g[u]) q.push(v);
	}
	for(auto i:f) 
	if(!i)
	{
		cout<<"No\n";
		return ;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
