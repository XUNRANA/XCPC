#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,ans;
int vt[2010][2010],dis[2010][2010],d[2010][2010],vt1[2010][2010];
int a[2010][2010];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool ck(int nx,int ny)
{
	if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]==-1) return 1;
	return 0;
}
char b[2010][2010];
void solve()
{
	cin>>n>>m>>x>>y;
	vector<pair<int,int>>p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=d[i][j]=1e9;
			char ch;
			cin>>ch;
			if(ch=='@') 
			{
				a[i][j]=1;
				p.push_back({i,j});
			}
			else if(ch=='#') a[i][j]=-1;
		}
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
	for(auto i:p) 
	{
		d[i.first][i.second]=0;
		q.push({0,{i.first,i.second}});
	}
	
	while(!q.empty())
	{
		int x1=q.top().second.first;
		int y1=q.top().second.second;
		q.pop();
		if(vt1[x1][y1]) continue;
		vt1[x1][y1]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x1+dx[i];
			int ny=y1+dy[i];
			if(ck(nx,ny)||vt1[nx][ny]) continue;
			if(d[nx][ny]>d[x1][y1]+1)
			{
				d[nx][ny]=d[x1][y1]+1;
				q.push({d[nx][ny],{nx,ny}});
			}
		}
	}
	int ans=1e9;
	dis[x][y]=0;
	q.push({0,{x,y}});
	while(!q.empty())
	{
		int x1=q.top().second.first;
		int y1=q.top().second.second;
		q.pop();
		if(vt[x1][y1]) continue;
		vt[x1][y1]=1;
		for(int i=0;i<4;i++)
		{
			int nx=x1+dx[i];
			int ny=y1+dy[i];
			if(ck(nx,ny)||ck(2*x-nx,2*y-ny)||vt[nx][ny]||vt[2*x-nx][2*y-ny]) continue;
			if(dis[nx][ny]>dis[x1][y1]+1)
			{
				dis[nx][ny]=dis[x1][y1]+1;
				if(!a[nx][ny]) q.push({dis[nx][ny],{nx,ny}});
			}
		}
	}
	for(auto i:p)
	{
		int x1=i.first;
		int y1=i.second;
		if(dis[x1][y1]!=1e9) ans=min(ans,dis[x1][y1]+d[2*x-x1][2*y-y1]);
	}
    if(ans==1e9) ans=-1;
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
